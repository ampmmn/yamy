//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// regex.cpp


#include "misc.h"
#include "regex.h"


namespace {

bool toUtf8(const std::wstring &i_text, std::string *o_text)
{
	if (i_text.empty()) {
		o_text->clear();
		return true;
	}
	int size = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS,
								   i_text.data(), static_cast<int>(i_text.size()),
								   NULL, 0, NULL, NULL);
	if (size == 0)
		return false;
	o_text->resize(size);
	return WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS,
								   i_text.data(), static_cast<int>(i_text.size()),
								   &(*o_text)[0], size, NULL, NULL) == size;
}

bool fromUtf8(absl::string_view i_text, std::wstring *o_text)
{
	if (i_text.empty()) {
		o_text->clear();
		return true;
	}
	int size = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
								i_text.data(), static_cast<int>(i_text.size()),
								NULL, 0);
	if (size == 0)
		return false;
	o_text->resize(size);
	return MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
								i_text.data(), static_cast<int>(i_text.size()),
								&o_text->at(0), size) == size;
}

}


const std::wstring &tsmatch::str(size_t i_index) const
{
	static const std::wstring empty;
	return i_index < m_values.size() ? m_values[i_index] : empty;
}


size_t tsmatch::size() const
{
	return m_values.size();
}


void tsmatch::clear()
{
	m_values.clear();
}


bool tsmatch::set(const std::vector<absl::string_view> &i_submatches)
{
	m_values.clear();
	m_values.resize(i_submatches.size());
	for (size_t i = 0; i < i_submatches.size(); ++ i) {
		if (i_submatches[i].data() == NULL)
			continue;
		if (!fromUtf8(i_submatches[i], &m_values[i])) {
			m_values.clear();
			return false;
		}
	}
	return true;
}


tregex::tregex()
		: m_flags(normal)
{
}


tregex::tregex(const wchar_t *i_pattern, flag_type i_flags)
		: m_flags(normal)
{
	assign(i_pattern ? std::wstring(i_pattern) : std::wstring(), i_flags);
}


tregex::tregex(const std::wstring &i_pattern, flag_type i_flags)
		: m_flags(normal)
{
	assign(i_pattern, i_flags);
}


tregex::tregex(const char *i_pattern, flag_type i_flags)
		: m_flags(normal)
{
	assign(i_pattern ? std::string(i_pattern) : std::string(), i_flags);
}


tregex::tregex(const std::string &i_pattern, flag_type i_flags)
		: m_flags(normal)
{
	assign(i_pattern, i_flags);
}


tregex::tregex(const tregex &i_regex)
		: m_flags(normal)
{
	assignUtf8(i_regex.m_patternUtf8, i_regex.m_flags);
	m_pattern = i_regex.m_pattern;
}


tregex &tregex::operator=(const tregex &i_regex)
{
	if (this != &i_regex) {
		assignUtf8(i_regex.m_patternUtf8, i_regex.m_flags);
		m_pattern = i_regex.m_pattern;
	}
	return *this;
}


bool tregex::assign(const std::wstring &i_pattern, flag_type i_flags)
{
	std::string patternUtf8;
	if (!toUtf8(i_pattern, &patternUtf8)) {
		m_pattern = i_pattern;
		m_patternUtf8.clear();
		m_flags = i_flags;
		m_regex.reset();
		m_error = "invalid UTF-16 pattern";
		return false;
	}
	m_pattern = i_pattern;
	return assignUtf8(patternUtf8, i_flags);
}


bool tregex::assign(const std::string &i_pattern, flag_type i_flags)
{
	m_patternUtf8 = i_pattern;
	m_flags = i_flags;
	m_error.clear();
	if (!fromUtf8(i_pattern, &m_pattern)) {
		m_regex.reset();
		m_error = "invalid UTF-8 pattern";
		return false;
	}
	return assignUtf8(i_pattern, i_flags);
}


bool tregex::assignUtf8(const std::string &i_pattern, flag_type i_flags)
{
	RE2::Options options;
	options.set_case_sensitive((i_flags & icase) == 0);
	m_patternUtf8 = i_pattern;
	m_flags = i_flags;
	m_error.clear();
	std::unique_ptr<RE2> regex(new RE2(i_pattern, options));
	if (!regex->ok()) {
		m_regex.reset();
		m_error = regex->error();
		return false;
	}
	m_regex.swap(regex);
	return true;
}


bool tregex::valid() const
{
	return m_regex.get() != NULL && m_regex->ok();
}


const std::string &tregex::error() const
{
	return m_error;
}


const std::wstring &tregex::str() const
{
	return m_pattern;
}


bool tregex::match(const std::wstring &i_text, RE2::Anchor i_anchor,
				  tsmatch *o_match) const
{
	std::string textUtf8;
	if (!toUtf8(i_text, &textUtf8))
		return false;
	return matchUtf8(textUtf8, i_anchor, o_match);
}


bool tregex::matchUtf8(absl::string_view i_text, RE2::Anchor i_anchor,
					   tsmatch *o_match) const
{
	if (!valid())
		return false;
	if (o_match)
		o_match->clear();
	int count = o_match ? m_regex->NumberOfCapturingGroups() + 1 : 0;
	std::vector<absl::string_view> submatches(static_cast<size_t>(count));
	if (!m_regex->Match(i_text, 0, i_text.size(), i_anchor,
						submatches.empty() ? NULL : &submatches[0], count))
		return false;
	return !o_match || o_match->set(submatches);
}


bool tregex::searchUtf8(const std::string &i_text, size_t i_start,
						 size_t *o_begin, size_t *o_end,
						 tsmatch *o_match) const
{
	if (!valid() || i_start > i_text.size())
		return false;
	if (o_match)
		o_match->clear();
	int count = o_match ? m_regex->NumberOfCapturingGroups() + 1 : 1;
	std::vector<absl::string_view> submatches(static_cast<size_t>(count));
	if (!m_regex->Match(i_text, i_start, i_text.size(), RE2::UNANCHORED,
						submatches.empty() ? NULL : &submatches[0], count))
		return false;
	size_t begin = static_cast<size_t>(submatches[0].data() - i_text.data());
	if (o_begin)
		*o_begin = begin;
	if (o_end)
		*o_end = begin + submatches[0].size();
	return !o_match || o_match->set(submatches);
}


bool regex_match(const std::wstring &i_text, tsmatch &o_match,
				 const tregex &i_regex)
{
	return i_regex.match(i_text, RE2::ANCHOR_BOTH, &o_match);
}


bool regex_search(const std::wstring &i_text, tsmatch &o_match,
				  const tregex &i_regex)
{
	return i_regex.match(i_text, RE2::UNANCHORED, &o_match);
}

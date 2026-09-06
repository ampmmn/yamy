//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// regex.h


#ifndef _REGEX_H
#  define _REGEX_H


#  include <memory>
#  include <string>
#  include <vector>
#  include <re2/re2.h>


class tsmatch
{
public:
	const std::wstring &str(size_t i_index) const;
	size_t size() const;

private:
	friend class tregex;
	void clear();
	bool set(const std::vector<absl::string_view> &i_submatches);

	std::vector<std::wstring> m_values;
};


class tregex
{
public:
	enum flag_type {
		normal = 0,
		icase = 1
	};

	tregex();
	explicit tregex(const wchar_t *i_pattern, flag_type i_flags = normal);
	explicit tregex(const std::wstring &i_pattern, flag_type i_flags = normal);
	explicit tregex(const char *i_pattern, flag_type i_flags = normal);
	explicit tregex(const std::string &i_pattern, flag_type i_flags = normal);
	tregex(const tregex &i_regex);
	tregex &operator=(const tregex &i_regex);

	bool assign(const std::wstring &i_pattern, flag_type i_flags = normal);
	bool assign(const std::string &i_pattern, flag_type i_flags = normal);
	bool valid() const;
	const std::string &error() const;
	const std::wstring &str() const;

	bool match(const std::wstring &i_text, RE2::Anchor i_anchor,
			   tsmatch *o_match = NULL) const;
	bool searchUtf8(const std::string &i_text, size_t i_start,
				   size_t *o_begin, size_t *o_end,
				   tsmatch *o_match = NULL) const;

private:
	bool assignUtf8(const std::string &i_pattern, flag_type i_flags);
	bool matchUtf8(absl::string_view i_text, RE2::Anchor i_anchor,
				   tsmatch *o_match) const;

	std::wstring m_pattern;
	std::string m_patternUtf8;
	flag_type m_flags;
	std::unique_ptr<RE2> m_regex;
	std::string m_error;
};


bool regex_match(const std::wstring &i_text, tsmatch &o_match,
				 const tregex &i_regex);
bool regex_search(const std::wstring &i_text, tsmatch &o_match,
				  const tregex &i_regex);


#endif // !_REGEX_H

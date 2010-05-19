var inputName = WScript.Arguments.Item(0);
var outputName = WScript.Arguments.Item(1);
if (inputName == null || outputName == null) {
	throw new Error("usage: CScirpt.exe makefunc.js <input file> <output file>");
}

var fso = WScript.CreateObject("Scripting.FileSystemObject");
if (fso == null) {
	throw new Error("can't create File System Object!");
}

var inputFile = fso.OpenTextFile(inputName, 1);
if (inputFile == null) {
	throw new Error("can't open " + inputName);
}

var outputFile = fso.CreateTextFile(outputName, true);
if (outputFile == null) {
	throw new Error("can't open " + outputName);
}

var line = "";

do {
} while (inputFile.ReadLine().match("BEGINING OF FUNCTION DEFINITION") == null);

do {
	var buf = inputFile.ReadLine();
	if (buf.match("///") == null) {
	    line += buf;
	}
} while (buf.match("END OF FUNCTION DEFINITION") == null);

inputFile.Close();

line = line.replace(/\s+/g, " ");

outputFile.WriteLine("// DO NOT EDIT");
outputFile.WriteLine("// this file is automatically generated by makefunc");
outputFile.WriteLine("// see dependency information in mayu-common.mak");
outputFile.WriteLine("");
outputFile.WriteLine("#ifdef FUNCTION_DATA");

var lines = line.split(";");
var names = new Array();
for (var n = 0; n < lines.length; n++) {
    var entry = lines[n].match(/^\s*\w+\s+func(\w+)\s*\(\s*FunctionParam\s*\*\s*\w+\s*,?\s*(.*?)\s*\)\s*$/);
    if (entry) {
	names[n] = name = entry[1];
	outputFile.WriteLine("class FunctionData_" + name + " : public FunctionData");
	outputFile.WriteLine("{");
	outputFile.WriteLine("public:");

	var args = entry[2].split(/\s*,\s*/);
	var argc = 0;
	var argIsReference = new Array();
	var argTypes = new Array();
	var argNames = new Array();
	var argDefaultValues = new Array();
	for (var i = 0; i < args.length; i++) {
	    var arg = args[i];
	    var isReference = 0;
	    var type = "";
	    var argName = "";
	    var defaultValue = "";

	    if (arg == "") continue;

	    if (arg.match(/^(.*\S)\s*=\s*(\S.*)$/)) {
		arg = RegExp.$1;
		defaultValue = RegExp.$2;
	    }
	    if (arg.match(/^(.*\S\s*\*)\s*i_(\w+)$/)) {
		type = RegExp.$1;
		argName = RegExp.$2;
	    } else if (arg.match(/^const\s*(.*\S)\s*&\s*i_(\w+)$/)) {
		type = RegExp.$1;
		argName = RegExp.$2;
		isReference = 1;
	    } else if (arg.match(/^(.*\S)\s*i_(\w+)$/)) {
		type = RegExp.$1;
		argName = RegExp.$2;
	    } else {
		throw new Error("parse error!");
	    }

	    argIsReference[i] = isReference;
	    argTypes[i] = type;
	    argNames[i] = argName;
	    argDefaultValues[i] = defaultValue;
	    argc++;
	}
	for (var i = 0; i < argc; i++) {
	    outputFile.WriteLine("  " + argTypes[i] + " m_" + argNames[i] + ";");
	}
	outputFile.WriteLine("");
	outputFile.WriteLine("public:");
	outputFile.WriteLine("  static FunctionData *create()");
	outputFile.WriteLine("  {");
	outputFile.WriteLine("    FunctionData_" + name + " *fd");
	outputFile.WriteLine("      = new FunctionData_" + name + ";");
	for (var i = 0; i < argc; i++) {
	    if (argDefaultValues[i]) {
		outputFile.WriteLine("    fd->m_"
				     + argNames[i]
				     + " = "
				     + argDefaultValues[i]
				     + ";");
	    }
	}
	outputFile.WriteLine("    return fd;");
	outputFile.WriteLine("  }");
	outputFile.WriteLine("  ");
	outputFile.WriteLine("  virtual void load(SettingLoader *i_sl)");
	outputFile.WriteLine("  {");
	if (argc == 0 || argDefaultValues[0]) {
	    outputFile.WriteLine("    if (!i_sl->getOpenParen(false, FunctionData_" + name + "::getName()))");
	    outputFile.WriteLine("      return;");
	} else {
	    outputFile.WriteLine("    i_sl->getOpenParen(true, FunctionData_" + name + "::getName()); // throw ...");
	}
	for (i = 0; i < argc; i++) {
	    if (argDefaultValues[i]) {
		outputFile.WriteLine("    if (i_sl->getCloseParen(false, FunctionData_" + name + "::getName()))");
		outputFile.WriteLine("      return;");
	    }
	    if (0 < i) {
		outputFile.WriteLine("    i_sl->getComma(false, FunctionData_" + name + "::getName()); // throw ...");
	    }
	    outputFile.WriteLine("    i_sl->load_ARGUMENT(&m_" + argNames[i] + ");");
	}
	outputFile.WriteLine("    i_sl->getCloseParen(true, FunctionData_" + name + "::getName()); // throw ...");
	outputFile.WriteLine("  }");
	outputFile.WriteLine("");
	outputFile.WriteLine("  virtual void exec(Engine *i_engine, FunctionParam *i_param) const");
	outputFile.WriteLine("  {");
	outputFile.Write("    i_engine->func" + name + "(i_param");
	for (i = 0; i < argc; i++) {
	    outputFile.Write(", m_" + argNames[i]);
	}
	outputFile.WriteLine(");");
  
	outputFile.WriteLine("  }");
	outputFile.WriteLine("");
	outputFile.WriteLine("  inline virtual const _TCHAR *getName() const");
	outputFile.WriteLine("  {");
	outputFile.WriteLine("    return _T(\"" + name + "\");");
	outputFile.WriteLine("  }");
	outputFile.WriteLine("");
	outputFile.WriteLine("  virtual tostream &output(tostream &i_ost) const");
	outputFile.WriteLine("  {");
	outputFile.WriteLine("    i_ost << _T(\"&\") << getName();");

	if ( 0 < argc ) {
	    outputFile.WriteLine("    i_ost << _T(\"(\");");
	}
	for (i = 0; i < argc; i++) {
	    if (i == argc - 1) {
		outputFile.WriteLine("    i_ost << m_" + argNames[i] + ";");
	    } else {
		outputFile.WriteLine("    i_ost << m_" + argNames[i] + " << _T(\", \");");
	    }
	}
	if ( 0 < argc ) {
	    outputFile.WriteLine("    i_ost << _T(\") \");");
	}
	outputFile.WriteLine("    return i_ost;");
	outputFile.WriteLine("  }");
	outputFile.WriteLine("");
	outputFile.WriteLine("  virtual FunctionData *clone() const");
	outputFile.WriteLine("  {");
	outputFile.WriteLine("    return new FunctionData_" + name + "(*this);");
	outputFile.WriteLine("  }");
	outputFile.WriteLine("};");
	outputFile.WriteLine("");
    }
}

outputFile.WriteLine("#endif // FUNCTION_DATA");
outputFile.WriteLine("");
outputFile.WriteLine("#ifdef FUNCTION_FRIEND");

for (var n = 0; n < names.length; n++) {
    var name = names[n];
    outputFile.WriteLine("friend class FunctionData_" + name + ";");
}

outputFile.WriteLine("#endif // FUNCTION_FRIEND");
outputFile.WriteLine("");
outputFile.WriteLine("#ifdef FUNCTION_CREATOR");
outputFile.WriteLine("FunctionCreator functionCreators[] = {");

for (var n = 0; n < names.length; n++) {
    var name = names[n];
    outputFile.WriteLine("  { _T(\"" + name + "\"), FunctionData_" + name + "::create },");
}

outputFile.WriteLine("};");
outputFile.WriteLine("#endif // FUNCTION_CREATOR");

outputFile.Close();

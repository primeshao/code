//
// Vivado(TM)
// rundef.js: a Vivado-generated Runs Script for WSH 5.1/5.6
// Copyright 1986-2015 Xilinx, Inc. All Rights Reserved.
//

var WshShell = new ActiveXObject( "WScript.Shell" );
var ProcEnv = WshShell.Environment( "Process" );
var PathVal = ProcEnv("PATH");
if ( PathVal.length == 0 ) {
  PathVal = "E:/Xilinx/SDK/2015.2/bin;E:/Xilinx/Vivado/2015.2/ids_lite/ISE/bin/nt64;E:/Xilinx/Vivado/2015.2/ids_lite/ISE/lib/nt64;E:/Xilinx/Vivado/2015.2/bin;";
} else {
  PathVal = "E:/Xilinx/SDK/2015.2/bin;E:/Xilinx/Vivado/2015.2/ids_lite/ISE/bin/nt64;E:/Xilinx/Vivado/2015.2/ids_lite/ISE/lib/nt64;E:/Xilinx/Vivado/2015.2/bin;" + PathVal;
}

ProcEnv("PATH") = PathVal;

var RDScrFP = WScript.ScriptFullName;
var RDScrN = WScript.ScriptName;
var RDScrDir = RDScrFP.substr( 0, RDScrFP.length - RDScrN.length - 1 );
var ISEJScriptLib = RDScrDir + "/ISEWrap.js";
eval( EAInclude(ISEJScriptLib) );


ISEStep( "vivado",
         "-log RAM_8_8.vds -m64 -mode batch -messageDb vivado.pb -notrace -source RAM_8_8.tcl" );



function EAInclude( EAInclFilename ) {
  var EAFso = new ActiveXObject( "Scripting.FileSystemObject" );
  var EAInclFile = EAFso.OpenTextFile( EAInclFilename );
  var EAIFContents = EAInclFile.ReadAll();
  EAInclFile.Close();
  return EAIFContents;
}
@echo off
set xv_path=E:\\Xilinx\\Vivado\\2015.2\\bin
call %xv_path%/xsim test_ComplementMultiplier_behav -key {Behavioral:sim_1:Functional:test_ComplementMultiplier} -tclbatch test_ComplementMultiplier.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0

@echo off
set xv_path=E:\\Xilinx\\Vivado\\2015.2\\bin
call %xv_path%/xelab  -wto 664592eab5784155898e585538916b9d -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot test_decision_behav xil_defaultlib.test_decision xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0

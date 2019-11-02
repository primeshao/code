# 
# Synthesis run script generated by Vivado
# 

debug::add_scope template.lib 1
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
set_msg_config -id {Synth 8-256} -limit 10000
set_msg_config -id {Synth 8-638} -limit 10000
create_project -in_memory -part xc7a100tcsg324-1

set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir {E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P7-1/P7-1.cache/wt} [current_project]
set_property parent.project_path {E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P7-1/P7-1.xpr} [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
read_verilog -library xil_defaultlib {{E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P7-1/P7-1.srcs/sources_1/new/PA4.v}}
synth_design -top PA4 -part xc7a100tcsg324-1
write_checkpoint -noxdef PA4.dcp
catch { report_utilization -file PA4_utilization_synth.rpt -pb PA4_utilization_synth.pb }

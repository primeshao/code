proc start_step { step } {
  set stopFile ".stop.rst"
  if {[file isfile .stop.rst]} {
    puts ""
    puts "*** Halting run - EA reset detected ***"
    puts ""
    puts ""
    return -code error
  }
  set beginFile ".$step.begin.rst"
  set platform "$::tcl_platform(platform)"
  set user "$::tcl_platform(user)"
  set pid [pid]
  set host ""
  if { [string equal $platform unix] } {
    if { [info exist ::env(HOSTNAME)] } {
      set host $::env(HOSTNAME)
    }
  } else {
    if { [info exist ::env(COMPUTERNAME)] } {
      set host $::env(COMPUTERNAME)
    }
  }
  set ch [open $beginFile w]
  puts $ch "<?xml version=\"1.0\"?>"
  puts $ch "<ProcessHandle Version=\"1\" Minor=\"0\">"
  puts $ch "    <Process Command=\".planAhead.\" Owner=\"$user\" Host=\"$host\" Pid=\"$pid\">"
  puts $ch "    </Process>"
  puts $ch "</ProcessHandle>"
  close $ch
}

proc end_step { step } {
  set endFile ".$step.end.rst"
  set ch [open $endFile w]
  close $ch
}

proc step_failed { step } {
  set endFile ".$step.error.rst"
  set ch [open $endFile w]
  close $ch
}

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000

start_step init_design
set rc [catch {
  create_msg_db init_design.pb
  debug::add_scope template.lib 1
  set_property design_mode GateLvl [current_fileset]
  set_property webtalk.parent_dir {E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P2/P2.cache/wt} [current_project]
  set_property parent.project_path {E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P2/P2.xpr} [current_project]
  set_property ip_repo_paths {{e:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P2/P2.cache/ip}} [current_project]
  set_property ip_output_repo {{e:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P2/P2.cache/ip}} [current_project]
  add_files -quiet {{E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P2/P2.runs/synth_1/adder.dcp}}
  link_design -top adder -part xc7a100tcsg324-1
  close_msg_db -file init_design.pb
} RESULT]
if {$rc} {
  step_failed init_design
  return -code error $RESULT
} else {
  end_step init_design
}

start_step opt_design
set rc [catch {
  create_msg_db opt_design.pb
  catch {write_debug_probes -quiet -force debug_nets}
  opt_design 
  write_checkpoint -force adder_opt.dcp
  catch {report_drc -file adder_drc_opted.rpt}
  close_msg_db -file opt_design.pb
} RESULT]
if {$rc} {
  step_failed opt_design
  return -code error $RESULT
} else {
  end_step opt_design
}

start_step place_design
set rc [catch {
  create_msg_db place_design.pb
  catch {write_hwdef -file adder.hwdef}
  place_design 
  write_checkpoint -force adder_placed.dcp
  catch { report_io -file adder_io_placed.rpt }
  catch { report_utilization -file adder_utilization_placed.rpt -pb adder_utilization_placed.pb }
  catch { report_control_sets -verbose -file adder_control_sets_placed.rpt }
  close_msg_db -file place_design.pb
} RESULT]
if {$rc} {
  step_failed place_design
  return -code error $RESULT
} else {
  end_step place_design
}

start_step route_design
set rc [catch {
  create_msg_db route_design.pb
  route_design 
  write_checkpoint -force adder_routed.dcp
  catch { report_drc -file adder_drc_routed.rpt -pb adder_drc_routed.pb }
  catch { report_timing_summary -warn_on_violation -max_paths 10 -file adder_timing_summary_routed.rpt -rpx adder_timing_summary_routed.rpx }
  catch { report_power -file adder_power_routed.rpt -pb adder_power_summary_routed.pb }
  catch { report_route_status -file adder_route_status.rpt -pb adder_route_status.pb }
  catch { report_clock_utilization -file adder_clock_utilization_routed.rpt }
  close_msg_db -file route_design.pb
} RESULT]
if {$rc} {
  step_failed route_design
  return -code error $RESULT
} else {
  end_step route_design
}


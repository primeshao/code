
�
scannot add Board Part %s available at %s as part %s specified in board_part file is either invalid or not available5*board28
$digilentinc.com:arty-s7-50:part0:1.02default:default2\
HE:/Xilinx/Vivado/2015.2/data/boards/board_files/arty-s7-50/B.0/board.xml2default:default2#
xc7s50csga324-12default:defaultZ49-26h px
�
scannot add Board Part %s available at %s as part %s specified in board_part file is either invalid or not available5*board26
"digilentinc.com:genesys2:part0:1.12default:default2X
DE:/Xilinx/Vivado/2015.2/data/boards/board_files/genesys2/H/board.xml2default:default2$
xc7k325tffg900-22default:defaultZ49-26h px
r
Command: %s
53*	vivadotcl2D
0synth_design -top ROM_8_8 -part xc7a100tcsg324-12default:defaultZ4-113h px
7
Starting synth_design
149*	vivadotclZ4-321h px
�
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2
	Synthesis2default:default2
xc7a100t2default:defaultZ17-347h px
�
0Got license for feature '%s' and/or device '%s'
310*common2
	Synthesis2default:default2
xc7a100t2default:defaultZ17-349h px
�
�The version limit for your license is '%s' and will expire in %s days. A version limit expiration means that, although you may be able to continue to use the current version of tools or IP with this license, you will not be eligible for any updates or new releases.
519*common2
2018.082default:default2
-4502default:defaultZ17-1223h px
�
%s*synth2�
rStarting Synthesize : Time (s): cpu = 00:00:04 ; elapsed = 00:00:05 . Memory (MB): peak = 279.941 ; gain = 82.883
2default:defaulth px
�
synthesizing module '%s'638*oasys2
ROM_8_82default:default2r
\E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P9-3/P9-3.srcs/sources_1/new/ROM_8_8.v2default:default2
12default:default8@Z8-638h px
[
%s*synth2F
2	Parameter WORD_SIZE bound to: 8 - type: integer 
2default:defaulth px
]
%s*synth2H
4	Parameter WORD_NUMBER bound to: 8 - type: integer 
2default:defaulth px
^
%s*synth2I
5	Parameter Address_SIZE bound to: 3 - type: integer 
2default:defaulth px
�
8referenced signal '%s' should be on the sensitivity list567*oasys2
CS_n2default:default2r
\E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P9-3/P9-3.srcs/sources_1/new/ROM_8_8.v2default:default2
132default:default8@Z8-567h px
�
8referenced signal '%s' should be on the sensitivity list567*oasys2
Address2default:default2r
\E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P9-3/P9-3.srcs/sources_1/new/ROM_8_8.v2default:default2
132default:default8@Z8-567h px
�
%s*synth2�
�
Warning: Trying to implement RAM in registers. Block RAM or DRAM implementation is not possible for one or more of the following reasons :
2default:defaulth px
g
%s*synth2R
>	1: Unable to determine number of words or word size in RAM. 
2default:defaulth px
F
%s*synth21
RAM dissolved into registers
2default:defaulth px
�
0Net %s in module/entity %s does not have driver.3422*oasys2
ROM2default:default2
ROM_8_82default:default2r
\E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P9-3/P9-3.srcs/sources_1/new/ROM_8_8.v2default:default2
112default:default8@Z8-3848h px
�
0Net %s in module/entity %s does not have driver.3422*oasys2
ROM2default:default2
ROM_8_82default:default2r
\E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P9-3/P9-3.srcs/sources_1/new/ROM_8_8.v2default:default2
112default:default8@Z8-3848h px
�
0Net %s in module/entity %s does not have driver.3422*oasys2
ROM2default:default2
ROM_8_82default:default2r
\E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P9-3/P9-3.srcs/sources_1/new/ROM_8_8.v2default:default2
112default:default8@Z8-3848h px
�
0Net %s in module/entity %s does not have driver.3422*oasys2
ROM2default:default2
ROM_8_82default:default2r
\E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P9-3/P9-3.srcs/sources_1/new/ROM_8_8.v2default:default2
112default:default8@Z8-3848h px
�
0Net %s in module/entity %s does not have driver.3422*oasys2
ROM2default:default2
ROM_8_82default:default2r
\E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P9-3/P9-3.srcs/sources_1/new/ROM_8_8.v2default:default2
112default:default8@Z8-3848h px
�
0Net %s in module/entity %s does not have driver.3422*oasys2
ROM2default:default2
ROM_8_82default:default2r
\E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P9-3/P9-3.srcs/sources_1/new/ROM_8_8.v2default:default2
112default:default8@Z8-3848h px
�
0Net %s in module/entity %s does not have driver.3422*oasys2
ROM2default:default2
ROM_8_82default:default2r
\E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P9-3/P9-3.srcs/sources_1/new/ROM_8_8.v2default:default2
112default:default8@Z8-3848h px
�
0Net %s in module/entity %s does not have driver.3422*oasys2
ROM2default:default2
ROM_8_82default:default2r
\E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P9-3/P9-3.srcs/sources_1/new/ROM_8_8.v2default:default2
112default:default8@Z8-3848h px
�
%done synthesizing module '%s' (%s#%s)256*oasys2
ROM_8_82default:default2
12default:default2
12default:default2r
\E:/Program Files_code/WORKSPACE_verilog_Vivado 2015.2/P9-3/P9-3.srcs/sources_1/new/ROM_8_8.v2default:default2
12default:default8@Z8-256h px
�
%s*synth2�
sFinished Synthesize : Time (s): cpu = 00:00:05 ; elapsed = 00:00:06 . Memory (MB): peak = 313.332 ; gain = 116.273
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
~Finished Constraint Validation : Time (s): cpu = 00:00:05 ; elapsed = 00:00:06 . Memory (MB): peak = 313.332 ; gain = 116.273
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
S
%s*synth2>
*Start Loading Part and Timing Information
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
H
%s*synth23
Loading part: xc7a100tcsg324-1
2default:defaulth px
T
Loading part %s157*device2$
xc7a100tcsg324-12default:defaultZ21-403h px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Loading Part and Timing Information : Time (s): cpu = 00:00:05 ; elapsed = 00:00:06 . Memory (MB): peak = 313.332 ; gain = 116.273
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished RTL Optimization Phase 2 : Time (s): cpu = 00:00:05 ; elapsed = 00:00:06 . Memory (MB): peak = 322.289 ; gain = 125.230
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
B
%s*synth2-

Report RTL Partitions: 
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
I
%s*synth24
 Start RTL Component Statistics 
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
H
%s*synth23
Detailed RTL Component Info : 
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
L
%s*synth27
#Finished RTL Component Statistics 
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
V
%s*synth2A
-Start RTL Hierarchical Component Statistics 
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
L
%s*synth27
#Hierarchical RTL Component report 
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
X
%s*synth2C
/Finished RTL Hierarchical Component Statistics
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
E
%s*synth20
Start Part Resource Summary
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2k
WPart Resources:
DSPs: 240 (col length:80)
BRAMs: 270 (col length: RAMB18 80 RAMB36 40)
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
H
%s*synth23
Finished Part Resource Summary
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Start Parallel Synthesis Optimization  : Time (s): cpu = 00:00:07 ; elapsed = 00:00:08 . Memory (MB): peak = 435.273 ; gain = 238.215
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
K
%s*synth26
"Start Cross Boundary Optimization
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Cross Boundary Optimization : Time (s): cpu = 00:00:07 ; elapsed = 00:00:08 . Memory (MB): peak = 436.488 ; gain = 239.430
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
~Finished Parallel Reinference  : Time (s): cpu = 00:00:07 ; elapsed = 00:00:08 . Memory (MB): peak = 436.488 ; gain = 239.430
2default:defaulth px
B
%s*synth2-

Report RTL Partitions: 
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
A
%s*synth2,
Start Area Optimization
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
zFinished Area Optimization : Time (s): cpu = 00:00:07 ; elapsed = 00:00:09 . Memory (MB): peak = 445.961 ; gain = 248.902
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Parallel Area Optimization  : Time (s): cpu = 00:00:07 ; elapsed = 00:00:09 . Memory (MB): peak = 445.961 ; gain = 248.902
2default:defaulth px
B
%s*synth2-

Report RTL Partitions: 
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
�
%s*synth2�
�Finished Parallel Synthesis Optimization  : Time (s): cpu = 00:00:07 ; elapsed = 00:00:09 . Memory (MB): peak = 445.961 ; gain = 248.902
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
C
%s*synth2.
Start Timing Optimization
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
|Finished Timing Optimization : Time (s): cpu = 00:00:07 ; elapsed = 00:00:09 . Memory (MB): peak = 445.961 ; gain = 248.902
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
B
%s*synth2-

Report RTL Partitions: 
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
B
%s*synth2-
Start Technology Mapping
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
{Finished Technology Mapping : Time (s): cpu = 00:00:07 ; elapsed = 00:00:09 . Memory (MB): peak = 445.961 ; gain = 248.902
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
B
%s*synth2-

Report RTL Partitions: 
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
<
%s*synth2'
Start IO Insertion
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
E
%s*synth20
Start Final Netlist Cleanup
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
H
%s*synth23
Finished Final Netlist Cleanup
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
uFinished IO Insertion : Time (s): cpu = 00:00:07 ; elapsed = 00:00:09 . Memory (MB): peak = 445.961 ; gain = 248.902
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
A
%s*synth2,

Report Check Netlist: 
2default:defaulth px
r
%s*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth px
r
%s*synth2]
I|      |Item              |Errors |Warnings |Status |Description       |
2default:defaulth px
r
%s*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth px
r
%s*synth2]
I|1     |multi_driven_nets |      0|        0|Passed |Multi driven nets |
2default:defaulth px
r
%s*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
L
%s*synth27
#Start Renaming Generated Instances
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Renaming Generated Instances : Time (s): cpu = 00:00:07 ; elapsed = 00:00:09 . Memory (MB): peak = 445.961 ; gain = 248.902
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
B
%s*synth2-

Report RTL Partitions: 
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
T
%s*synth2?
++-+--------------+------------+----------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
I
%s*synth24
 Start Rebuilding User Hierarchy
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Rebuilding User Hierarchy : Time (s): cpu = 00:00:07 ; elapsed = 00:00:09 . Memory (MB): peak = 445.961 ; gain = 248.902
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
~Start Renaming Generated Ports : Time (s): cpu = 00:00:07 ; elapsed = 00:00:09 . Memory (MB): peak = 445.961 ; gain = 248.902
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Renaming Generated Ports : Time (s): cpu = 00:00:07 ; elapsed = 00:00:09 . Memory (MB): peak = 445.961 ; gain = 248.902
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
H
%s*synth23
Start Writing Synthesis Report
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
>
%s*synth2)

Report BlackBoxes: 
2default:defaulth px
G
%s*synth22
+-+--------------+----------+
2default:defaulth px
G
%s*synth22
| |BlackBox name |Instances |
2default:defaulth px
G
%s*synth22
+-+--------------+----------+
2default:defaulth px
G
%s*synth22
+-+--------------+----------+
2default:defaulth px
>
%s*synth2)

Report Cell Usage: 
2default:defaulth px
@
%s*synth2+
+------+------+------+
2default:defaulth px
@
%s*synth2+
|      |Cell  |Count |
2default:defaulth px
@
%s*synth2+
+------+------+------+
2default:defaulth px
@
%s*synth2+
|1     |LUT1  |     1|
2default:defaulth px
@
%s*synth2+
|2     |LUT2  |     1|
2default:defaulth px
@
%s*synth2+
|3     |IBUF  |     2|
2default:defaulth px
@
%s*synth2+
|4     |OBUFT |     8|
2default:defaulth px
@
%s*synth2+
+------+------+------+
2default:defaulth px
B
%s*synth2-

Report Instance Areas: 
2default:defaulth px
K
%s*synth26
"+------+---------+-------+------+
2default:defaulth px
K
%s*synth26
"|      |Instance |Module |Cells |
2default:defaulth px
K
%s*synth26
"+------+---------+-------+------+
2default:defaulth px
K
%s*synth26
"|1     |top      |       |    12|
2default:defaulth px
K
%s*synth26
"+------+---------+-------+------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
�
%s*synth2�
�Finished Writing Synthesis Report : Time (s): cpu = 00:00:07 ; elapsed = 00:00:09 . Memory (MB): peak = 445.961 ; gain = 248.902
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
p
%s*synth2[
GSynthesis finished with 0 errors, 0 critical warnings and 10 warnings.
2default:defaulth px
�
%s*synth2�
~Synthesis Optimization Runtime : Time (s): cpu = 00:00:05 ; elapsed = 00:00:06 . Memory (MB): peak = 445.961 ; gain = 218.715
2default:defaulth px
�
%s*synth2�
Synthesis Optimization Complete : Time (s): cpu = 00:00:07 ; elapsed = 00:00:09 . Memory (MB): peak = 445.961 ; gain = 248.902
2default:defaulth px
?
 Translating synthesized netlist
350*projectZ1-571h px
b
-Analyzing %s Unisim elements for replacement
17*netlist2
22default:defaultZ29-17h px
g
2Unisim Transformation completed in %s CPU seconds
28*netlist2
02default:defaultZ29-28h px
H
)Preparing netlist for logic optimization
349*projectZ1-570h px
r
)Pushed %s inverter(s) to %s load pin(s).
98*opt2
02default:default2
02default:defaultZ31-138h px
{
!Unisim Transformation Summary:
%s111*project29
%No Unisim elements were transformed.
2default:defaultZ1-111h px
R
Releasing license: %s
83*common2
	Synthesis2default:defaultZ17-83h px
�
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
122default:default2
122default:default2
02default:default2
02default:defaultZ4-41h px
[
%s completed successfully
29*	vivadotcl2 
synth_design2default:defaultZ4-42h px
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2"
synth_design: 2default:default2
00:00:062default:default2
00:00:082default:default2
526.6252default:default2
299.3792default:defaultZ17-268h px
�
sreport_utilization: Time (s): cpu = 00:00:01 ; elapsed = 00:00:00.094 . Memory (MB): peak = 526.625 ; gain = 0.000
*commonh px
}
Exiting %s at %s...
206*common2
Vivado2default:default2,
Sun Nov 24 23:32:49 20192default:defaultZ17-206h px
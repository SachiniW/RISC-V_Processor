# cp ../generated/Core.v Core.v
rm -r obj_dir
rm -
echo "-----------------------------------------------------"
figlet RV 32I Core
echo "-----------------------------------------------------"

case "$2" in 
  new)
  	echo "Enter the C code to be evaluated"
  	nano ../../PyRV32I/hello_world.c
  	echo "Compiling and loading the program ..."
  	cd ../../PyRV32I
  	python3 comp.py hello_world.c &>-;
  	cp instruction_memory.mem ../rtl/src/ 
  	cd ../rtl/src
  ;;
esac

case "$1" in
  eval) 
  	echo -e "Micro-architecture designs available for evaluation, \n\n [1] - Single-Cycle Design \n [2] - Multi-Cycle Design \n [3] - Pipelined Design (No data forwarding) \n [4] - Pipelined Design (With data forwarding)\n"
  	read -p "Enter the design number [1/2/3/4] : " x
  	case "$x" in 
  	1) 
  		echo -e "\nEvaluating with RV32I Single-Cycle Design ...\n"
    		verilator -Wall --cc Core.v --exe Drivers/Core.cpp 
		make -C obj_dir -f VCore.mk &>-
		obj_dir/VCore
	;;
	2)
  		echo -e "\nEvaluating with RV32I Multi-Cycle Design ...\n"
    		verilator -Wall --cc CoreMS.v --exe Drivers/CoreMS.cpp 
		make -C obj_dir -f VCoreMS.mk &>-
		obj_dir/VCoreMS
	;;
	3)
  		echo -e "\nEvaluating with RV32I Pipelined Design (No data forwarding) ...\n"
    		verilator -Wall --cc CorePipe.v --exe Drivers/CorePipe.cpp 
		make -C obj_dir -f VCorePipe.mk &>-
		obj_dir/VCorePipe
	;;
	4)
  		echo -e "\nEvaluating with RV32I Pipelined Design (With data forwarding) ...\n"
    		verilator -Wall --cc CorePipeForwarding.v --exe Drivers/CorePipeForwarding.cpp 
		make -C obj_dir -f VCorePipeForwarding.mk &>-
		obj_dir/VCorePipeForwarding
	;;
	*)     
   		echo -e "Evaluating with RV32I Pipelined Design ...\n"
    		verilator -Wall --cc Core.v --exe Drivers/Core.cpp 
		make -C obj_dir -f VCore.mk &>-
		obj_dir/VCore
	;;
	esac
  	
  ;;
    *) 
   	echo -e "Evaluating with RV32I Pipelined Design ...\n"
    	verilator -Wall --cc CorePipeForwarding.v --exe Drivers/CorePipeForwarding.cpp 
	make -C obj_dir -f VCorePipeForwarding.mk &>-
	obj_dir/VCorePipeForwarding
    ;;
esac



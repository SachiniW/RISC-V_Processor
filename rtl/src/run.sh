# cp ../generated/Core.v Core.v
#rm -r obj_dir
verilator -Wall --cc Core.v --exe Core.cpp
make -C obj_dir -f VCore.mk
obj_dir/VCore

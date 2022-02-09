import os
import sys
# try:
# except:
# 	filename='new_test.c'
filename=str(sys.argv[1])
print(filename)
flag= './toolChain/bin/riscv32-unknown-elf-'
os.system(flag+'gcc '+filename+' printer.c -s -o K_1.elf -nostartfiles -march=rv32ia -mabi=ilp32 -fPIC');

os.system(flag+'objcopy K_1.elf  -O verilog g.hex');
os.system(flag+'objdump  K_1.elf -d >  test.txt');
mile = open('g.hex','r')
out = open('instruction_memory.mem','w')
out1 = open('data_hex2.mem','w')
lines= mile.readlines()

int_addr=int(lines.pop(0)[1:],16)
curr_addr= 0
memsize = 21
mem=[]
mem2 = []
for i in range (1<<memsize):
	mem.append(["00","00","00","00"])
	mem2.append("00")
	mem2.append("00")
	mem2.append("00")
	mem2.append("00")


for val in lines:
	if ('@' not in val):
		vals=val.split()
		for value in vals:
			mem[curr_addr>>2][3-(curr_addr & 0b11)] = value
			mem2[curr_addr] = value
			if ((curr_addr%4)==0):
				pass #print hex(curr_addr),mem[curr_addr>>2]
			curr_addr = curr_addr + 1
		
	else:
		curr_addr = int(val[1:],16) - int_addr
		# print hex(curr_addr)






for i in range (1<<memsize):
	out.write(''.join(mem[i])+'\n')
	out1.write(''.join(mem2[4*i])+'\n')
	out1.write(''.join(mem2[4*i+1])+'\n')
	out1.write(''.join(mem2[4*i+2])+'\n')
	out1.write(''.join(mem2[4*i+3])+'\n')

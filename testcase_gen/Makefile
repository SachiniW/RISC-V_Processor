all:
	rm -rf *.o *.elf *.hex *.txt *.v *.s *.mem
	python3 PART_INS_GEN.py
	cp instruction_memory.mem ../rtl/
clean:
	rm -rf *.o *.elf *.hex *.txt *.v *.s *.mem

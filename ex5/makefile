#file: makefile

a.out: main.o Mission1.o Mission2And3.o Mission4.o Mission5.o FuncMission6.o missionMenu.o GetInput.o
	gcc main.o Mission1.o Mission2And3.o Mission4.o Mission5.o FuncMission6.o missionMenu.o GetInput.o

main.o: main.c Mission1.h Mission2And3.h Mission4.h Mission5.h GetInput.h FuncMission6.h missionMenu.h
	gcc -c main.c

Mission5.o: Mission5.c Mission5.h
	gcc -c Mission5.c

Mission4.o: Mission4.c Mission4.h
	gcc -c Mission4.c

Mission2And3.o: Mission2And3.c Mission2And3.h
	gcc -c Mission2And3.c

Mission1.o: Mission1.c Mission1.h
	gcc -c Mission1.c

FuncMission6.o: FuncMission6.c FuncMission6.h
	gcc -c FuncMission6.c

missionMenu.o: missionMenu.c missionMenu.h
	gcc -c missionMenu.c
GetInput.o: GetInput.c GetInput.h
	gcc -c GetInput.c







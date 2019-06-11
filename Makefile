EXENAME = mp1
OBJS = Coordinator.o Enemy.o EnemyManager.o Pickup.o PickupManager.o Player.o main.o
CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpthread -lm
all: $(EXENAME)
$(EXENAME): $(OBJS) $(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)


Coordinator.o: EnemyManager.h EnemyManager.cpp PickupManager.h PickupManager.cpp Player.h Player.cpp ofmain.h ofxcenteredtruetypefont.h Coordinator.h Coordinator.cpp Enemy.h Enemy.cpp ofxgui.h
Enemy.o: Enemy.h Enemy.cpp Coordinator.h Coordinator.cpp ofmain.h
EnemyManager.o: Player.h Player.cpp Enemy.h Enemy.cpp EnemyManager.h EnemyManager.cpp
Pickup.o: ofmain.h Pickup.h Pickup.cpp
PickupManager.o: Pickup.h Pickup.cpp PickupManager.h PickupManager.cpp
Player.o: ofmain.h ofxgui.h Player.h Player.cpp
main.cpp: ofmain.h ofxgui.h Coordinator.h main.cpp
clean: -rm -f *.o $(EXENAME)

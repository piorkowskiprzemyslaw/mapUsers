CC=g++
CFLAGS=-c -Wall -pedantic

all: mapUsers

mapUsers: project.o Interpreter.o Connection.o SocketException.o OptionMask.o Data.o Data.o MSISDNumber.o IMSINumber.o IMEINumber.o LAINumber.o CINumber.o RAINumber.o VMSCNumber.o SGSNumber.o EventNumber.o Helper.o AnonymousMockup.o SaveToDatabase.o PrepareSQLStatement.o
	$(CC) project.o Interpreter.o Connection.o SocketException.o OptionMask.o Data.o MSISDNumber.o IMSINumber.o IMEINumber.o LAINumber.o CINumber.o RAINumber.o VMSCNumber.o SGSNumber.o EventNumber.o Helper.o AnonymousMockup.o SaveToDatabase.o PrepareSQLStatement.o -lpthread -lpqxx -lpq -o mapUsers  

project.o: project.cpp Interpreter.cpp Interpreter.h Connection.cpp Connection.h
	$(CC) $(CFLAGS) project.cpp -o project.o

Connection.o: Connection.cpp Connection.h SocketException.cpp SocketException.h
	$(CC) $(CFLAGS) Connection.cpp -o Connection.o

SocketException.o: SocketException.cpp SocketException.h
	$(CC) $(CFLAGS) SocketException.cpp -o SocketException.o

Helper.o: Helper.cpp Helper.h
	$(CC) $(CFLAGS) Helper.cpp -o Helper.o

Interpreter.o: Interpreter.cpp Interpreter.h FieldName.h OptionMask.cpp OptionMask.h Data.cpp Data.h
	$(CC) $(CFLAGS) Interpreter.cpp -o Interpreter.o

OptionMask.o: OptionMask.cpp OptionMask.h FieldName.h
	$(CC) $(CFLAGS) OptionMask.cpp -o OptionMask.o

Data.o: Data.cpp Data.h FieldName.h MSISDNumber.cpp MSISDNumber.h IMSINumber.cpp IMSINumber.h IMEINumber.h IMEINumber.cpp LAINumber.h LAINumber.cpp CINumber.h CINumber.cpp RAINumber.h RAINumber.cpp VMSCNumber.h VMSCNumber.cpp SGSNumber.h SGSNumber.cpp EventNumber.h EventNumber.cpp
	$(CC) $(CFLAGS) Data.cpp -o Data.o 

MSISDNumber.o: MSISDNumber.cpp MSISDNumber.h Helper.cpp Helper.h
	$(CC) $(CFLAGS) MSISDNumber.cpp -o MSISDNumber.o

IMSINumber.o: IMSINumber.cpp IMSINumber.h Helper.cpp Helper.h
	$(CC) $(CFLAGS) IMSINumber.cpp -o IMSINumber.o

IMEINumber.o: IMEINumber.cpp IMEINumber.h Helper.cpp Helper.h
	$(CC) $(CFLAGS) IMEINumber.cpp -o IMEINumber.o

LAINumber.o: LAINumber.cpp LAINumber.h
	$(CC) $(CFLAGS) LAINumber.cpp -o LAINumber.o

CINumber.o: CINumber.cpp CINumber.h
	$(CC) $(CFLAGS) CINumber.cpp -o CINumber.o

RAINumber.o: RAINumber.cpp RAINumber.h
	$(CC) $(CFLAGS) RAINumber.cpp -o RAINumber.o

VMSCNumber.o: VMSCNumber.cpp VMSCNumber.h
	$(CC) $(CFLAGS) VMSCNumber.cpp -o VMSCNumber.o

SGSNumber.o: SGSNumber.cpp SGSNumber.h
	$(CC) $(CFLAGS) SGSNumber.cpp -o SGSNumber.o

EventNumber.o: EventNumber.cpp EventNumber.h
	$(CC) $(CFLAGS) EventNumber.cpp -o EventNumber.o

AnonymousMockup.o: AnonymousMockup.cpp AnonymousMockup.h
	$(CC) $(CFLAGS) AnonymousMockup.cpp -o AnonymousMockup.o

SaveToDatabase.o: SaveToDatabase.cpp SaveToDatabase.h
	$(CC) $(CFLAGS) SaveToDatabase.cpp -o SaveToDatabase.o

PrepareSQLStatement.o: PrepareSQLStatement.cpp PrepareSQLStatement.h
	$(CC) $(CFLAGS) PrepareSQLStatement.cpp -o PrepareSQLStatement.o

clean:
	rm -rf *o mapUsers


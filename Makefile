report: main.o Control.o View.o ReportGenerator.o Record.o RegionGenerator.o PercentChangeGenerator.o SubRegionGenerator.o
	g++ -o report main.o Control.o View.o ReportGenerator.o Record.o RegionGenerator.o PercentChangeGenerator.o SubRegionGenerator.o

main.o: main.cc
	g++ -c main.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc

Record.o: Record.cc Record.h
	g++ -c Record.cc

RegionGenerator.o: RegionGenerator.cc RegionGenerator.h
	g++ -c RegionGenerator.cc

PercentChangeGenerator.o: PercentChangeGenerator.cc PercentChangeGenerator.h
	g++ -c PercentChangeGenerator.cc

SubRegionGenerator.o: SubRegionGenerator.cc SubRegionGenerator.h
	g++ -c SubRegionGenerator.cc

clean:
	rm -f *.o PercentChange.txt SubRegion.txt Region.txt report

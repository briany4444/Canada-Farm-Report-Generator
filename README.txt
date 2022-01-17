Author: Brian Yang 101140298

Purpose:
the purpose of this program is to take data from statistics Canada about the
number of farms and animals in a particular region and display the percent changes
over 5 years and calculate the proportions of these animals for province (and Canada) to the user.
The program must also find the largest subregion per province (based on number of animals) and
also generate files for the user for each report they select from the menu.

Source Files: Control.cc main.cc PercentChangeGenerator.cc Record.cc RegionGenerator.cc ReportGenerator.cc
              SubRegionGenerator.cc View.cc

Header Files: Control.h CompareBehaviour.h AscBehaviour.h DescBehaviour.h Map.h PercentChangeGenerator.h Record.h ReportData.h
              SubRegionGenerator.h View.h RegionGenerator.h ReportGenerator.h

To compile and create executable: make

To run executable: ./report

To clean: make clean

#
# Makefile.c++
#
# Instructions:
#
# 1. Edit Makefile using vi or emacs:
#    a. rename target, if desired
#    b. add list of source files at SRCS = ...
# 2. % touch Makefile.dep
# 3. % make depend
# 4. % make
#

TARGET = borne
CC = g++
CFLAGS = -Wall -O -g 

#Version materielle
INCLDIRS =
LIBDIRS = 

#dependance librairie libsmartcard_borne (voir git)
LIBS64 = -lsmartcardcpp_borne_x64 

SRCS = lecteurcarte.cpp borne.cpp voyants.cpp prise.cpp boutons.cpp timer.cpp generateur_save.cpp base_client.cpp 

OBJS = ${SRCS:.cpp=.o} 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLDIRS) -o $@ $(OBJS) $(LIBS64)

$(OBJS):
	$(CC) $(CFLAGS) $(INCLDIRS) -c $*.cpp

depend:
	$(CC) -MM $(SRCS) $(INCLDIRS) > Makefile.dep

clean:
	rm -f $(OBJS) core

veryclean: clean
	rm -f $(TARGET) a.out *.*~

include Makefile.dep


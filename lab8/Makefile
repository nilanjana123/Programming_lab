SHELL := /bin/bash

LIBDIR := ./lib
OBJDIR := ./objs
EXEDIR := ./bin
HDIR   := ./include
SRCDIR := ./src
LOGDIR := ./LOGG

EXE    := $(EXEDIR)/ans
SRCS   := $(wildcard src/*.cpp)
HEADRS := $(wildcard include/*.h)
LIBS   := $(addprefix $(LIBDIR)/,libadditional.a libscalarops.a libmatrixops.so)
OBJS   := $(addprefix $(OBJDIR)/,$(patsubst src/%.cpp,%.o,$(wildcard src/*.cpp)))
TEMP   := temp.txt

i := $(EXEDIR)/run.in
o := $(EXEDIR)/run.out

vpath %.cpp src
vpath %.h include
vpath %.o $(OBJDIR)

all: $(EXE)
	@echo "Finished Compiling!"

$(EXE): $(OBJS) $(LIBS) | $(EXEDIR)
	@g++ -o $@ $(OBJS)
	@echo $(EXE)" Executable created!!"
	
$(OBJDIR)/ans.o: $(SRCS) $(HEADRS) | $(OBJDIR)
	@g++ -o $@ -c -I include src/ans.cpp
	@echo $@" Created !!"

$(OBJDIR)/MatrixOps.o: src/MatrixOps.cpp $(SRCS) $(HEADRS) | $(OBJDIR)
	@g++ -fpic -o $@ -c -I include $<
	@echo $@" Created !!"

$(OBJDIR)/ExtractOps.o: ExtractOps.cpp $(SRCS) $(HEADRS) | $(OBJDIR)
	@g++ -o $@ -c -I include $<
	@echo $@" Created !!"

$(OBJDIR)/ScalarOps.o: ScalarOps.cpp $(SRCS) $(HEADRS) | $(OBJDIR)
	@g++ -o $@ -c -I include $<
	@echo $@" Created !!"

$(OBJDIR)/ManageOps.o: ManageOps.cpp $(SRCS) $(HEADRS) | $(OBJDIR)
	@g++ -o $@ -c -I include $<
	@echo $@" Created !!"

$(OBJDIR)/LoggerAns.o: src/LoggerAns.cpp $(SRCS) $(HEADRS) | $(OBJDIR)
	@g++ -o $@ -c -I include $<
	@echo $@" Created !!"

$(LIBDIR)/libadditional.a: $(OBJDIR)/ExtractOps.o $(OBJDIR)/ManageOps.o $(OBJDIR)/LoggerAns.o | $(LIBDIR)
	@ar rcs $@ $^
	@echo $@" Created !!"
	
$(LIBDIR)/libscalarops.a: $(OBJDIR)/ScalarOps.o | $(LIBDIR)
	@ar rcs $@ $^
	@echo $@" Created !!"

$(LIBDIR)/libmatrixops.so: $(OBJDIR)/MatrixOps.o | $(LIBDIR)
	@g++ -shared -o $@ $<
	@echo $@" Created !!"

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo $(OBJDIR) " Created!!"

$(LIBDIR):
	@mkdir -p $(LIBDIR)
	@echo $(OBJDIR) " Created!!"

$(EXEDIR):
	@mkdir -p $(EXEDIR)
	@echo $(OBJDIR) " Created!!"

$(LOGFILE):
	@mkdir -p $(LOGDIR)
	@cat $(LOGDIR)/logg.txt	
	@echo $(OBJDIR) " Created!!"

.PHONY: clean
clean:
	@rm -rf $(EXEDIR) $(OBJDIR) $(LIBDIR) $(TEMP) 
	@echo "Make Clean Successfull.."

.PHONY: build
build: $(EXE)
	@echo "Build successfull.."

.PHONY: libs
libs: $(LIBDIR)/libscalarops.a $(LIBDIR)/libmatrixops.so | $(LIBDIR)
	@echo "Libraries created successfully!!"
	#rm $(OBJDIR)/*.o

.PHONY: prepare
prepare:
	@echo -n "Enter input filepath :" ;\
	read i ;\
	echo -n "Enter output filepath :" ;\
	read o ;\
	rm -rf $(TEMP);\
	if [[ -f $$i || $$i -eq "" ]] ;then echo "Input file : '"$$i"' exists"; else echo "Input file : '"$$i"' does not exists"; fi ;\
	if [[ -f $$o || $$i -eq "" ]] ;then echo "Output file : '"$$o"' exists"; else echo "Output file : '"$$o"' does not exists"; fi; \
	if [[ -f $$i && -f $$o ]] ;then echo $$i >>$(TEMP) ; echo $$o  >>$(TEMP); echo "Successfully prepared !! Ready to run ..."; else read -p "Do you want to prepare once again? [y/n]:" yn ; if [ $$yn = 'y' ];then echo $$yn ; make prepare; else echo "Prepare Failed !!"; fi ;\
	fi
	
.PHONY: run
run: $(EXE) $(TEMP) 
	@echo "Run Started!!"
	@$(eval i := $(shell sed -n '1 p' $(TEMP))) 
	@$(eval o := $(shell sed -n '2 p' $(TEMP)))
	@if [ -f $(i) ]; then $(EXE) < $(i)  > temp.out ;cat temp.out; diff temp.out $(o) && echo "No difference with."$(o) || echo "Not Matched .";\
	else \
	echo "file not exists";\
	fi 
	@rm -rf temp.out $(TEMP) $(EXEDIR)/run1.in $(EXEDIR)/run1.out

$(TEMP):
	@rm -rf $(EXEDIR)/run1.in $(EXEDIR)/run1.out
	@touch $(TEMP)
	@touch $(EXEDIR)/run1.in
	@touch $(EXEDIR)/run1.out
	@echo "bin/run1.in" >> $(TEMP)
	@echo "bin/run1.out" >> $(TEMP)
	
.PHONY: tests
tests: $(addprefix test,$(patsubst tests/sample%.in,%,$(wildcard tests/*.in)))
	@echo "All Test cases successfully completed.. "

.PHONY: test%
test%: tests/sample%.in ./tests/sample%.out $(EXE) 
	@echo "__________________________________________________________________________"
	@echo $@" Starts!!"
	@$(EXE) < $(word 1,$^) > $@.out ; cat $@.out && echo "" || echo "not computable."
	@diff $@.out $(word 2,$^) && echo "No difference with "$(word 1,$^) || echo "Not Matched ."
	@rm $@.out
	@echo $@" ran successfully..."
	@echo "__________________________________________________________________________"
	



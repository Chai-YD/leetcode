OBJ="test"
FLAG="-g"

.PHONY:${OBJ} 
all: clean ${OBJ} 

${OBJ}:
	g++  test.cc demo.cc -o ${OBJ} ${FLAG} 

clean:
	rm -rf ${OBJ} 

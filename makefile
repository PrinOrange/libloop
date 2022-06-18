#	libloop	1.0.0 version - GNU makefile
#		Libloop is the instance of asynchron-event model in Unix-like platform.

SOURCE_FILES_PATH = ./src
OBJECT_FILES_PATH = ./out/obj
OUTPUT_FILES_PATH = ./out

main: 			mkdir main.o queue.o threadpool.o event.o
				@ cc 		$(OBJECT_FILES_PATH)/main.o 								\
							$(OBJECT_FILES_PATH)/queue.o 								\
							$(OBJECT_FILES_PATH)/threadpool.o 							\
						-o 	$(OUTPUT_FILES_PATH)/main

main.o:			$(SOURCE_FILES_PATH)/main.c
				@ cc	-c $(SOURCE_FILES_PATH)/main.c 									\
						-o $(OBJECT_FILES_PATH)/main.o

threadpool.o:	$(SOURCE_FILES_PATH)/threadpool.c 										\
				$(SOURCE_FILES_PATH)/threadpool.h
				@ cc 	-c $(SOURCE_FILES_PATH)/threadpool.c 							\
						-o $(OBJECT_FILES_PATH)/threadpool.o

queue.o:		$(SOURCE_FILES_PATH)/queue.c 											\
				$(SOURCE_FILES_PATH)/queue.h
				@ cc 	-c $(SOURCE_FILES_PATH)/queue.c 								\
						-o $(OBJECT_FILES_PATH)/queue.o

event.o:		$(SOURCE_FILES_PATH)/event.c 											\
				$(SOURCE_FILES_PATH)/event.h
				@ cc 	-c $(SOURCE_FILES_PATH)/event.c 								\
						-o $(OBJECT_FILES_PATH)/event.o

.PHONY:			clean	test	mkdir	head

mkdir:			
				@ echo "creating the output folder..."
				@ mkdir -p $(OUTPUT_FILES_PATH)
				@ echo "creating the object folder..."
				@ mkdir -p $(OBJECT_FILES_PATH)

test:			$(OUTPUT_FILES_PATH)/main
				@ echo "...start the test..."
				@ $(OUTPUT_FILES_PATH)/main
				@ echo "\n...test finished..."

head:			$(SOURCE_FILES_PATH)
				@ cp $(SOURCE_FILES_PATH)/*.h ./include			

clean:
				@ rm -rf $(OUTPUT_FILES_PATH)
				@ echo "finished cleanning che output folder."

# Nom du programme
NAME = Animal

# Compilateur et options
CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# Dossiers
SRCDIR =
OBJDIR =
INCDIR =

RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m

# Fichiers sources et objets
SRCS = AnimalClass/Animal.cpp \
		DogClass/Dog.cpp \
		CatClass/Cat.cpp \
		

OBJS = $(SRCS:.cpp=.o)
		
#paths
SRC_PATH =

OBJ_PATH = $(addprefix $(OBJDIR), $(OBJS))

# Compilation du programme
all: $(NAME)
		@printf "$(BLUE)Welcome to EX00 of CPP04\n$(RESET)"

$(NAME): $(OBJ_PATH)
		@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
		@$(CC) $(CXXFLAGS) $(OBJ_PATH) -o $(NAME)
		@echo "$(GREEN)Finished [$(NAME)]$(RESET)"
		

# Compilation des fichiers objets
$(OBJDIR)%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling Contact [$<]...$(RESET)"
	@$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

# Nettoyage des fichiers objets
clean:
	@if [ -d "$(OBJDIR)" ]; then \
	rm -rf $(OBJDIR); \
	echo "$(BLUE)Deleting all objects from /ex00...$(RESET)"; else \
	echo "No objects to remove from /ex00."; \
	fi;

# Nettoyage complet
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(BLUE)Deleting $(NAME) from ex00...$(RESET)"; else \
	echo "No Executable to remove from ex00."; \
	fi;

# Recompiler proprement
re: fclean all

.PHONY: all clean fclean re
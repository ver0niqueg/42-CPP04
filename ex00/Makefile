# Program name
NAME = Animal

# Compiler and flags
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Directories
OBJDIR = obj

RESET  = \033[0m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m

# Source files
SRCS = main.cpp \
		AnimalClass/Animal.cpp \
		DogClass/Dog.cpp \
		CatClass/Cat.cpp \
		WrongAnimalClass/WrongAnimal.cpp \
		WrongCatClass/WrongCat.cpp \

# Object files inside obj/
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

# Default target
all: $(NAME)
	@printf "$(BLUE)Welcome to EX00 of CPP04\n$(RESET)"

# Link step
$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

# Compile step (pattern rule)
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling [$<]...$(RESET)"
	@$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)Finished [$@]$(RESET)"

# Clean object files
clean:
	@rm -rf $(OBJDIR)
	@echo "$(BLUE)Deleting all objects from /ex00...$(RESET)"

# Full clean
fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)Deleting $(NAME) from ex00...$(RESET)"

# Rebuild
re: fclean all

.PHONY: all clean fclean re
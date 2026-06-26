NAME		= iter

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

OBJDIR		= .objects
DEPDIR		= .deps

SRCS		= main.cpp
OBJS		= $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS		= $(SRCS:%.cpp=$(DEPDIR)/%.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR) $(DEPDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -MF $(DEPDIR)/$*.d -c $< -o $@
# -MMD generates .d file listing the headers the .cpp file depends on
# -MP adds "dummy rules" to avoid errors if a header gets deleted
# -MF $*DEPDIR)/$*.d to write the .d file to the .deps folder instead of default location

$(OBJDIR) $(DEPDIR):
	mkdir -p $@

-include $(DEPS)

clean:
	rm -rf $(OBJDIR) $(DEPDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

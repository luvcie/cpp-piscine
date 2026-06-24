NAME		= serializer

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

OBJDIR		= .objects
DEPDIR		= .deps

SRCS		= main.cpp Serializer.cpp
OBJS		= $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS		= $(SRCS:%.cpp=$(DEPDIR)/%.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR) $(DEPDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -MF $(DEPDIR)/$*.d -c $< -o $@

$(OBJDIR) $(DEPDIR):
	mkdir -p $@

-include $(DEPS)

clean:
	rm -rf $(OBJDIR) $(DEPDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

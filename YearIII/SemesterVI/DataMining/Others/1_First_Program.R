
mean(1:5)

#------------Getting Help in R ---------------------------------------------------------------#
?mean #opens the help page for the mean function
?"+" #opens the help page for addition
?"if" #opens the help page for if, used for branching code
??plotting #searches for topics containing words like "plotting"
??"regression model" #searches for topics containing phrases like this

help("mean")
help("+")
help("if")
help.search("plotting")
help.search("regression model")
help("c")
a_vector <- c(1, 3, 6, 10)   
apropos("vector")    # results contain the variable you just created, a_vector, and all other variables 
                     # that contain the string vector
apropos("z$")        #find all variables that end in z
apropos("[4-9]")     #find all variables containing a number between 4 and 9


example(plot)
demo() #list all demonstrations
demo(colors)

#------------------Installing packages------------------------------------------------------------#
install.packages("installr") #download and install the package named installr
library(installr) #load the installr package
install.RStudio() #download and install the RStudio IDE
install.Rtools() #Rtools is needed for building your own packages
install.git() #git provides version control for your code


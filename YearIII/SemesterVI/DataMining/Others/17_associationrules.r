
setwd("C:\\Users\\shalini\\Desktop\\Rprograms")
getwd()
dir()
data(Titanic)
str(Titanic)
View(Titanic)

# read AR data converted from titanic data from website http://www.cs.toronto.edu/~delve/
#data/titanic/desc.html
titan <- read.table("./dataset.data", header=F)
View(titan)

names(titan) <- c("Class","Age", "Sex", "Survived")
View(titan)

install.packages("arules")
library(arules)
search()

# find association rules with default settings
#supp=0.1, ; 2) conf=0.8, 3) maxlen=10,
#rules.all <- apriori(titanic.raw)
rules.all <- apriori(titan)
quality(rules.all) <- round(quality(rules.all), digits=3)
rules.all

inspect(rules.all)


#---------------------------------start here-----------------------------------#


#rules with rhs containing "Survived" only

#restricted rules
#rules <- apriori(titanic.raw, control = list(verbose=F), parameter = list(minlen=2, supp=0.005, conf=0.8),appearance = list(rhs=c("Survived=No", "Survived=Yes"),default="lhs"))
rules <- apriori(titan, control = list(verbose=F), parameter = list(minlen=2, supp=0.005, conf=0.8),appearance = list(rhs=c("Survived=no", "Survived=yes"),default="lhs"))
quality(rules) <- round(quality(rules), digits=2)
rules.sorted <- sort(rules, by="lift")
inspect(rules.sorted)

#restricting LHS
rules <- apriori(titan, control = list(verbose=F),parameter = list(minlen=3, supp=0.002, conf=0.7),appearance = list(rhs=c("Survived=yes"),lhs=c("Class=1st", "Class=2nd", "Class=3rd","Age=child", "Age=adult"),default="none"))
quality(rules) <- round(quality(rules), digits=4)
rules.sorted <- sort(rules, by="lift")
inspect(rules.sorted)

#plotting AR
install.packages("arulesViz")
library(arulesViz)
search()

plot(rules.all)
plot(rules.all, method="grouped")


#another dataset market basket
data(Groceries)
inspect(Groceries[1:5])  #to see first 5 transactions

# Create an item frequency plot for the top 10 items
itemFrequencyPlot(Groceries,topN=10,type="absolute")

# Get the rules
rules <- apriori(Groceries, parameter = list(supp = 0.001, conf = 0.8))

# Show the top 5 rules, but only 2 digits
options(digits=2)
inspect(rules[1:5])
summary(rules)  #summary statistics

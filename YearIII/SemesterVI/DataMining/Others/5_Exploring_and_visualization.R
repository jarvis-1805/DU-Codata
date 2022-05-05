
#_______________________EXPLORING AND VISUALIZATION_________________________

data("worldcup", package = "faraway")
worldcup

data("nepali", package = "faraway")
nepali

# Summary Statistics on nepali dataset

#mean
mean(nepali$wt, na.rm = TRUE)

#median
median(nepali$wt, na.rm = TRUE)

#variance
var(nepali$wt, na.rm = TRUE)

#standard deviation
sd(nepali$wt, na.rm = TRUE)

#Mean Absolute Difference
mad(nepali$ht, na.rm = TRUE)

#Minimun and Maximum
min(nepali$wt, na.rm = TRUE)
max(nepali$wt, na.rm = TRUE)


#Quanties
quantile(nepali$wt, na.rm = TRUE)
IQR(nepali$wt, na.rm = TRUE)

#Five number Summary
fivenum(nepali$wt,na.rm = TRUE)

# Dataset Summary
summary(nepali)


#________________________PLOTTING______________________

#SCATTER PLOTS
#base [nepali]
with(nepali,plot(ht,wt, main="Weight versus Height" , xlab="Height(in cms)", 
             ylab="Weight(in kgs)", col= "blue", pch=18, log="xy"))

#lattice [nepali]
(scatter_lattice<- xyplot(wt~ht, nepali,main="Weight versus Height" , xlab="Height(in cms)", 
       ylab="Weight(in kgs)", col= "blue", pch=18,scales = list(log=TRUE))) 

(scatter_latice_update <- update(scatter_lattice, col = "violet", pch = 20))

#ggplot2[nepali]

ggplot(nepali, aes(x = ht, y = wt)) + 
  geom_point(size = 0.5) + 
  ggtitle("Weight versus Height") + 
  xlab("Height (cm)") + ylab("Weight (kg)")

#another version

nepali$sex [nepali$sex == 1] <- "Male"
nepali$sex [nepali$sex == 2] <- "Female"

ggplot(nepali, aes(x = ht, y = wt, color = sex)) + 
  geom_point(size = 0.5) + 
  ggtitle("Weight versus Height") + 
  xlab("Height (cm)") + ylab("Weight (kg)")


#uisng worldcup dataset
ggplot(worldcup, aes(x = Time, y = Passes,
                     color = Position, size = Shots)) + 
  geom_point()




# multiple plot layout[worldcup]

positions <- levels(worldcup$Position)
plot_numbers <- seq_along(positions)
layout(matrix(plot_numbers, ncol = 4))
for(pos in positions) {
  world_subset <- subset(worldcup, Position == pos)
  with(world_subset,  plot(Time, Passes, main = pos))
}

#using lattice[worldcup]
xyplot(Passes ~ Time | Position, worldcup,scales = list (relation="same",log=TRUE ,y=list(log=TRUE), 
                                                         alternating = FALSE), layout=c(2,2))


# using ggplot2 [worldcup]
ggplot(worldcup,aes(Time, Passes)) +
  geom_point() +
  ggtitle("Passes vs Time") +
  facet_wrap(~ Position, ncol = 4) +
  theme(axis.text.x = element_text(angle = -30))

#LINE PLOT

#base
with(nepali,plot(ht,wt, type="l" ,main="Weight versus Height" , xlab="Height(in cms)", 
                 ylab="Weight(in kgs)", col= "blue", pch=18))


#lattice
(scatter_lattice<- xyplot(wt~ht, nepali,type="l",main="Weight versus Height" , xlab="Height(in cms)", 
                          ylab="Weight(in kgs)", col= "blue", pch=18,scales = list(log=TRUE))) 


#ggplot2
ggplot(nepali, aes(x = ht, y = wt)) + 
  geom_line() + 
  ggtitle("Weight versus Height") + 
  xlab("Height (cm)") + ylab("Weight (kg)")

#HISTOGRAM
#base
with(nepali, hist(wt, "FD", freq=FALSE, 
              main="Distribution for Children's Weight(in kgs)"))

#lattice
histogram(~ wt, nepali, type= "count", main="Distribution for Children's Weight(in kgs)")

#ggplot2
ggplot(nepali, aes(wt,..density..)) +
  geom_histogram() 

#BOX PLOTS
#base[worldcup]
boxplot(Passes~Position,worldcup)

#lattice
bwplot(Passes~Position,worldcup)

#ggplot2
ggplot(worldcup,aes(Position,Passes))+
geom_boxplot()

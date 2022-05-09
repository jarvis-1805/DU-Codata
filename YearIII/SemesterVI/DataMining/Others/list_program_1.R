#setwd("C:\\Users\\shalini\\Desktop\\Rprograms")

setwd("E:\\E_Backup_20.7.2020\\BSc(H)CS\\Data_Mining\\Rprograms")

datafile <- file.choose()          #"./people.txt"

peoplefile <- read.table(datafile,header=TRUE,sep=",")

peoplefile  #display entire table

edit(peoplefile)

install.packages("sqldf")

library(sqldf)

#help("sqldf")

#RULE SET 1
peoplefile

query1 <- "SELECT
                            AGE,
                            AGEGROUP,
                            HEIGHT,
                            STATUS,
                            YEARSMARRIED
                        FROM
                            peoplefile
                        WHERE
                            AGE >=0 AND AGE <=150"
sqldf(query1)

#RULE SET 2
query2 <- "SELECT
                    AGE,
                    AGEGROUP,
                    HEIGHT,
                    STATUS,
                    YEARSMARRIED
                FROM
                    peoplefile
                WHERE
                    AGE > YEARSMARRIED"
sqldf(query2)

#RULE SET 3
query3 <- "SELECT
                  AGE,
                  AGEGROUP,
                  HEIGHT,
                  STATUS,
                  YEARSMARRIED
              FROM
                  peoplefile
              WHERE
                      STATUS='married' OR STATUS='single'OR STATUS='widowed' "
sqldf(query3)

#RULE SET 4
query4 <- "SELECT
                AGE,
                AGEGROUP,
                HEIGHT,
                STATUS,
                YEARSMARRIED
          FROM
                peoplefile
          WHERE
                AGE < 18 AND AGEGROUP = 'child' OR
                AGE BETWEEN 18 AND 65 AND AGEGROUP = 'adult' OR 
                AGE > 65 AND AGEGROUP = 'elderly' "
sqldf(query4)

peoplefile


# Summary Statistics on peoplefile dataset
#mean
mean(peoplefile$Age,na.rm = TRUE)
mean(peoplefile$HEIGHT,na.rm = TRUE) 
mean(peoplefile$YEARSMARRIED,na.rm = TRUE) 

#median
median(peoplefile$AGE,na.rm = TRUE)
median(peoplefile$HEIGHT,na.rm = TRUE) 
median(peoplefile$YEARSMARRIED,na.rm = TRUE) 

#variance
var(peoplefile$AGE,na.rm = TRUE)
var(peoplefile$HEIGHT,na.rm = TRUE) 
var(peoplefile$YEARSMARRIED,na.rm = TRUE) 



#standard deviation
sd(peoplefile$AGE,na.rm = TRUE)
sd(peoplefile$HEIGHT,na.rm = TRUE) 
sd(peoplefile$YEARSMARRIED,na.rm = TRUE) 


#Mean Absolute Difference
mad(peoplefile$AGE,na.rm = TRUE)
mad(peoplefile$HEIGHT,na.rm = TRUE) 
mad(peoplefile$YEARSMARRIED,na.rm = TRUE) 


#Minimun and Maximum
min(peoplefile$AGE,na.rm = TRUE)
min(peoplefile$HEIGHT,na.rm = TRUE) 
min(peoplefile$YEARSMARRIED,na.rm = TRUE) 

max(peoplefile$AGE,na.rm = TRUE)
max(peoplefile$HEIGHT,na.rm = TRUE) 
max(peoplefile$YEARSMARRIED,na.rm = TRUE) 


#Quanties
quantile(peoplefile$AGE,na.rm = TRUE)
quantile(peoplefile$HEIGHT,na.rm = TRUE) 
quantile(peoplefile$YEARSMARRIED,na.rm = TRUE) 

IQR(peoplefile$AGE,na.rm = TRUE)
IQR(peoplefile$HEIGHT,na.rm = TRUE) 
IQR(peoplefile$YEARSMARRIED,na.rm = TRUE) 

#Five number Summary
fivenum(peoplefile$AGE,na.rm = TRUE)
fivenum(peoplefile$HEIGHT,na.rm = TRUE) 
fivenum(peoplefile$YEARSMARRIED,na.rm = TRUE) 


# Dataset Summary
summary(peoplefile)


#________________________PLOTTING______________________
#SCATTER PLOTS
peolplefile

with(peoplefile,plot(AGE,HEIGHT, main="Age versus Height" , xlab="Age", 
                        ylab="Height", col= "blue", pch=18, log="xy"))



#lattice
library(lattice)
(scatter_lattice<- xyplot(AGE~HEIGHT, peoplefile,main="Age versus Height" , xlab="Age", 
                          ylab="Height", col= "blue", pch=18,scales = list(log=TRUE))) 

(scatter_latice_update <- update(scatter_lattice, col = "violet", pch = 20))


###############################################################
# ggplot
library(ggplot2)

ggplot(peoplefile, aes(x = AGE, y = HEIGHT)) + 
  geom_point(size = 0.5) + 
  ggtitle("Age versus Height") + 
  xlab("Age") + ylab("Height")

#another version
peoplefile
peoplefile$AGEGROUP [peoplefile$AGEGROUP == 1] <- "adult"
peoplefile$AGEGROUP [peoplefile$AGEGROUP == 2] <- "child"
peoplefile$AGEGROUP [peoplefile$AGEGROUP == 3] <- "elderly"



#ggplot(nepali, aes(x = ht, y = wt, color = sex)) + 
#  geom_point(size = 0.5) + 
#  ggtitle("Weight versus Height") + 
#  xlab("Height (cm)") + ylab("Weight (kg)")

peoplefile

ggplot(peoplefile, aes(x = AGE, y = HEIGHT, color = AGEGROUP )) + 
  geom_point(size = 0.5) + 
  ggtitle("Age versus Height") + 
  xlab("Age") + ylab("Height")

#######################################################################################

#using worldcup dataset
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
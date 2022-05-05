#_________________MANIPULATING DATA FRAMES______________________

data("worldcup", package = "faraway")

data("nepali", package = "faraway")


# Adding new Column

nepali$BMI <- nepali$wt/((nepali$ht/100)^2) #wt is weight(in Kgs) ht is height(in cms)
nepali

nepali$BMI <- with(nepali, wt/((ht/100)^2))

nepali <- within(nepali, BMI <- wt/((ht/100)^2))

nepali <- mutate(nepali, BMI = wt/((ht/100)^2))


#Reading partial data

(subset(worldcup,Tackles > 15, c("Team", "Position", "Tackles","Saves")))

# Reading using sqldf

install.packages("sqldf")
library(sqldf)

query_from_worldcup <- "SELECT
                            Team,
                            Position,
                            Tackles,
                            Saves
                        FROM
                            worldcup
                        WHERE
                            Tackles > 15 OR
                            Saves > 5"
sqldf(query_from_worldcup)

# drop columns

(subset(worldcup, select = -c(5,6))) # necessary to pass index 

#else
drops <- c("Passes","Tackles")
worldcup_new <- worldcup[ , !(names(worldcup) %in% drops)]
head(worldcup_new)

#Dealing with Missing Values

# vector with missing data
NA_vector <- c(1:4, NA, 6:7, NA)

is.na(NA_vector)


# data frame with missing data
NA_dataframe <- data.frame(col1 = c(1:3, NA),
                 col2 = c("this", NA,"is", "text"), 
                 col3 = c(TRUE, FALSE, TRUE, TRUE), 
                 col4 = c(2.5, 4.2, 3.2, NA),
                 stringsAsFactors = FALSE)

is.na(NA_dataframe)

# identify NAs in specific data frame column
is.na(NA_dataframe$col4)

# identify location of NAs in vector
which(is.na(NA_vector))


# identify count of NAs in data frame
sum(is.na(NA_dataframe))

#Recode Missing Values with mean

NA_vector[is.na(NA_vector)] <- mean(NA_vector, na.rm = TRUE)
round(NA_vector,2)

NA_dataframe$col4[is.na(NA_dataframe$col4)] <- mean(NA_dataframe$col4, na.rm = TRUE)
NA_dataframe

#Exclude Missing Values

complete.cases(NA_dataframe)

# subset with complete.cases to get complete cases
NA_dataframe[complete.cases(NA_dataframe), ]

# or use na.omit() to get same as above
na.fail(na.omit(NA_dataframe))

# or subset with `!` operator to get incomplete cases
NA_dataframe[!complete.cases(NA_dataframe), ]

#using na.fail
na.fail(NA_dataframe)

na.fail(NA_dataframe[complete.cases(NA_dataframe), ])


setwd("~/Documents/TOP/MY CPP PACKAGES/parsing-exercise/")

library(dplyr)
library(magrittr)

n <- 10

temperature <- rnorm(n-1) %>% 
  as.character %>% 
  c("ef;gr;gr") 

set.seed(1234)
station <- c("aaaaaaa", "b", "c") %>% 
  sample(n, replace = TRUE) 

dplyr::data_frame(station, temperature) %>% 
  write.table("data/stations.csv", sep = ";", row.names = FALSE, 
              col.names = FALSE, quote = FALSE)




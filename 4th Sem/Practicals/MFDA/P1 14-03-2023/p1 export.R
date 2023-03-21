student <- data.frame(
  stud_id = c (1:10),
  stud_name = c("Nikhil","Om","Shruti","Roy","Joy","Priya","Ravi","Ram","Sham","Riya"),
  marks = c("89","91","59","85","87","82","93","80","90","93"),
  gender = c("Male","Male","Female","Male","Male","Female","Male","Male","Male","Female")
)
# Print data frame.
print(student)
write.csv(student,"C:\\Users\\student.CT-LAB3-16\\Desktop\\student.csv")
print("data exportesd")

#Checking data of file by importing
reading_data <- read.csv("C:\\Users\\student.CT-LAB3-16\\Desktop\\student.csv")
print(reading_data)

write.table(student,file ="C:\\Users\\student.CT-LAB3-16\\Desktop\\new_data.txt", sep ="\t",row.name = TRUE,col.names = NA)
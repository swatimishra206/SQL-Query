# Write your MySQL query statement below
SELECT 
    score,
    DENSE_RANK() OVER (ORDER BY score DESC) AS `rank`
FROM Scores
ORDER BY score DESC;

 # dense_rank == **window** function hai jo data ko ranking dene ke kaam mai aata hai

# SQL mein normal functions (jaise SUM, COUNT) poori table ko samet kar ek row bana dete hain (Aggregate kar dete hain). Lekin humein har ek row ko barkarar rakhna tha aur ranking dikhani thi.

#**OVER clause ka kaam hai DENSE_RANK() ko batana ki ranking kis basis par aur kis order mein karni hai.

#Agar aap sirf DENSE_RANK() likhdoge, toh SQL confuse ho jayega ki: "Bhai, rank toh de dun, par kis column ke hisab se? Badhte kram (ascending) mein ya ghtate kram (descending) mein?" 

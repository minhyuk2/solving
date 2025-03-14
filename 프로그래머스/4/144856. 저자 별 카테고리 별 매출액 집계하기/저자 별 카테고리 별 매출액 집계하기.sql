# -- 코드를 입력하세요
SELECT B.AUTHOR_ID, A.AUTHOR_NAME, B.CATEGORY , SUM(B.PRICE * SALES) AS TOTAL_SALES
FROM BOOK AS B
JOIN BOOK_SALES AS C ON C.BOOK_ID = B.BOOK_ID
JOIN AUTHOR AS A ON A.AUTHOR_ID = B.AUTHOR_ID 
WHERE YEAR(SALES_DATE) = 2022 AND MONTH(SALES_DATE) = 1
GROUP BY AUTHOR_ID, CATEGORY
ORDER BY AUTHOR_ID ASC, CATEGORY DESC;


# SELECT BOOK_ID ,SALES_DATE FROM BOOK_SALES WHERE YEAR(SALES_DATE)  = '2022' AND MONTH(SALES_DATE) = '01'  GROUP BY BOOK_ID;
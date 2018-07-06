import System.IO
import Data.Char
import System.Random (randomRIO)

geraPseudoRandom val = randomRIO (1,val)

{- This code is from Data.List.Split module -}
splitOn :: (a -> Bool) -> [a] -> [[a]]
splitOn _ [] = []
splitOn f l@(x:xs)
  | f x = splitOn f xs
  | otherwise = let (h,t) = break f l in h:(splitOn f t)

{- this function remove \n from each string in list-}
removeN :: [[Char]] -> [[Char]]
removeN list
  | list == [] = list
  | otherwise = (tail (head list)) : (removeN (tail list))

{- this method take every single part of a question and answers and put in a single ==> matriz of each question -}
converterListaParaMatriz :: [[Char]] -> [[[Char]]]
converterListaParaMatriz (p:a:b:c:d:r:list)
  | list /= [] = ([p]++[a]++[b]++[c]++[d]++[r]):(converterListaParaMatriz list)
  | otherwise = ([p]++[a]++[b]++[c]++[d]++[r]):[]

randomizaMatriz :: [[[Char]]] -> [[Char]]-> [[[Char]]]
randomizaMatriz list newHead = newHead : [x | x <- list, x /= newHead]



cabecalho :: IO ()
cabecalho = do
 putStrLn (". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .")
 putStrLn (". ______________________________ S H O W ______________________________ .")
 putStrLn (". ________________________________ D O ________________________________ .")
 putStrLn (". ____________________________ M I L H A O ____________________________ .")
 putStrLn (". _____________________________________________________________________ .")
 putStrLn (".  Teste seus conhecimentos e concorra ao premio maximo de R$ 1 milhao  .")
 putStrLn (". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .")


menuCategorias :: IO ()
menuCategorias = do
  putStrLn "Qual categoria de questoes voce deseja?"
  putStrLn "1 - Computacao"
  putStrLn "2 - Conhecimentos Gerais"


lerQuestoes :: String -> IO ([[Char]])
lerQuestoes categoria = do
    if(categoria == "1") then do
      handle <- openFile "questoes_cc.txt" ReadMode
      contents <- hGetContents handle
      let questoes = (splitOn (==';') contents)
      return ((head questoes) : (removeN (tail questoes)))
    else do
      handle <- openFile "questoes_cc.txt" ReadMode
      contents <- hGetContents handle
      let questoes = (splitOn (==';') contents)
      return ((head questoes) : (removeN (tail questoes))) {- [[CHAR]]-}


joga :: [[[Char]]] -> Int -> IO ()
joga [] _ = print "Tu ganho mizeravi"
joga questoes premio =  do
  putStrLn (( head questoes )!!0)
  putStrLn (( head questoes )!!1)
  putStrLn (( head questoes )!!2)
  putStrLn (( head questoes )!!3)
  putStrLn (( head questoes )!!4)
  input <- getLine
  if (( head questoes )!!5 == input) then do
    joga (tail questoes) (premio+100)
  else do
    print "Erro Mizeravi"
main :: IO ()
main = do
 cabecalho
 putStrLn "Diga-me o seu nome: "
 nome <- getLine
 menuCategorias
 categoria <- getLine
 questoes <- lerQuestoes categoria
 rand <- geraPseudoRandom (length $ converterListaParaMatriz questoes)
 print rand
 joga (last [randomizaMatriz (converterListaParaMatriz questoes) (converterListaParaMatriz questoes !! (rand-1)) | x <- [1..rand]]) 0{- Matriz randomizada uma unica vez-}
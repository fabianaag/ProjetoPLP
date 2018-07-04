import System.IO
import Data.Char

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


lerQuestoes :: String -> IO ()
lerQuestoes categoria = do
    if(categoria == "1") then do
      handle <- openFile "questoes_cc.txt" ReadMode
      contents <- hGetContents handle
      putStrLn contents
      hClose handle
    else do
      handle <- openFile "questoes_ge.txt" ReadMode
      contents <- hGetContents handle
      putStrLn contents
      hClose handle


main :: IO ()
main = do
 cabecalho
 putStrLn "Diga-me o seu nome: "
 nome <- getLine
 menuCategorias
 categoria <- getLine
 lerQuestoes categoria

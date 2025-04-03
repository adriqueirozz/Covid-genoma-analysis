# Análise de Genoma - Covid e Influenza A (H1N1)

## Descrição do Projeto  
Este projeto implementa uma solução para a questão de análise de genoma, contando repetições de blocos de 6 bases nitrogenadas em sequências genéticas. A implementação segue os requisitos obrigatórios, utilizando uma **tabela hash personalizada** para armazenar e contar as ocorrências dos blocos de DNA.  

## Estrutura dos Arquivos  
- **`main.cpp`**: Contém o código-fonte da solução, incluindo a implementação da tabela hash, a conversão de string para inteiro e a leitura/escrita dos arquivos.  
- **`sequencesFasta.txt`**: Arquivo de entrada principal, contendo a sequência do genoma do **Coronavírus (NC_045512.2)**.  
- **`arquivoSaida.txt`**: Arquivo de saída correspondente a `sequencesFasta.txt`, contendo os blocos de 6 bases e suas respectivas contagens.  
- **`sequencesFasta2.txt`**: Arquivo de entrada criado para testes adicionais, contendo a sequência do genoma do **vírus da Influenza A (H1N1)**.  
- **`arquivoSaida2.txt`**: Arquivo de saída correspondente a `sequencesFasta2.txt`, contendo a contagem dos blocos de 6 bases para o genoma do H1N1.  

## Observações  
Todos os requisitos da questão foram implementados, incluindo:  
✅ Implementação da **hash table** com tratamento de colisões (encadeamento externo ou double hashing).  
✅ **Conversão string → inteiro** para a função de espalhamento.  
✅ **Leitura e escrita de arquivos** conforme exigido.  
✅ **Arquivo de entrada alternativo** (`sequencesFasta2.txt`) para validar o programa com outro genoma.  


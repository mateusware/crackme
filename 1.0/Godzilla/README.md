# Godzilla
[![C++](https://img.shields.io/badge/C++-%2300599C.svg?logo=c%2B%2B&logoColor=white)](#)
![img](https://img.shields.io/badge/Level-1.0-green)

# Flowchart
<img width="1185" height="675" alt="image" src="https://github.com/user-attachments/assets/18db22a0-61bf-40b6-ab2d-e73ad1add4cf" />

A essencia do código trabalha da mesma maneira como foi representada acima, a aplicação inicia, começa o loop, pega oque o usuário digitou e começa a verificar. Como é um programa muito simples, tem como ser reversado/crackado totalmente de maneira estática, sem a necessidade obrigatória de debugar o programa. 

A única ferramenta que foi usada para resolver esse módulo foi ``IDA Pro (ou GHIDRA)``, como o programa não tem nenhum tipo de prevenção (ofuscação) contra algum tipo de reversão, fica ainda sim mais fácil, aliás é bem como em jogos, até então o processo de ofuscação em massa, pode acontecer que o programa fique mais lento para processar o proprio sistema de ofuscação.

Como o programa não tem nenhum tipo de ofuscação, é o principal motivo por não ter outra ferramenta fora a de descompilação, seguindo esse raciocínio, eu coloquei o Godzilla dentro do **IDA Pro** e abri a aba de strings **(View > Open Subviews > Strings)**, em seguida, fui atrás de strings usada no programa, principalmente o "Access granted!", que é o nosso objetivo, conseguir burlar o sistema de login, ou melhor, conseguir a senha para burlar-lo.

Me deparei com essa tela:
<img width="758" height="107" alt="image" src="https://github.com/user-attachments/assets/553e1102-862b-4778-9bba-e834f26956f7" />

Aconselho primeiramente ver como funciona, ver a arquitetura da aplicação, que linguagem ele utiliza, ou mesmo se existe algum tipo de empacotamento, virtualização. Por mais que eu esteja ciente que não tenha nada do genero no Godzilla, até então foi eu que criei, eu aconselho fortemente ficar atento como o programa funciona, por que pode acontecer que o programa não tenha um sistema de segurança ou mesmo seja mal configurado, como por exemplo, caso a aplicação seja em CSharp, fica ainda mais fácil reversar com DnSpy.

Como já foi dito anteriormente, eu já tenho noção em que linguagem foi desenvolvida, mas no caso do C++ é comum que você encontre uma estrutura como essa:
```asm
 lea     rdx, aGodzillaLogin ; "- GODZILLA LOGIN\n"
 mov     rcx, cs:?cout@std@@3V?$basic_ostream@DU?$char_traits@D@std@@@1@A ; std::basic_ostream<char,std::char_traits<char>> std::cout
 call    sub_14000120D

 lea     rdx, asc_14000AD54 ; "-\n\n"
 mov     rcx, cs:?cout@std@@3V?$basic_ostream@DU?$char_traits@D@std@@@1@A ; std::basic_ostream<char,std::char_traits<char>> std::cout
 call    sub_14000120D

 lea     rdx, aInputPassword ; "Input password: \n"
 mov     rcx, cs:?cout@std@@3V?$basic_ostream@DU?$char_traits@D@std@@@1@A ; std::basic_ostream<char,std::char_traits<char>> std::cout
 call    sub_14000120D
```

Vendo essa estrutura, como basic_ostream, pertence a biblioteca nativa do C++ ([std::basic_ostream](https://en.cppreference.com/cpp/io/basic_ostream)), ela é responsável pela saida de dados (output) do programa. E se tratando que os ponteiros são Rdx, Rcx.. se trata de um programa com a arquitetura 64-bit, a diferença de uma arquitetura para outra não muda muito, o objetivo é o mesmo. Enfim, 

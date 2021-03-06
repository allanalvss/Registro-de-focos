# Registro-de-focos
O Registro de focos tem como principal objetivo cadastrar os bairros da cidade e os focos de dengue encontrados em cada um deles.A figura abaixo apresenta a tela inicial da aplicação.


![](figuras/inicial.png)


Ademais, o aplicação apresenta uma janela para estatísticas, na qual são apresentados a "Média de focos" encontrados e consequentemente os bairros classisificados com maior e menor risco.

![](figuras/estat.png)

# Inserção dos dados

Os dados necessários para a aplicação são o nome do bairro e número de focos registrados naquele local. É necessário preencher os Line Edit representados pelos labels (Bairro e Quantidade de Focos).E logo após isso o botão inserir irá atualializar a tabela e classificar o nível de risco de cada bairro cadastrado. Contudo, caso o usuário deseje limpar a tabela, a função Remover linha( acionada através do push button) remove uma linha por vez da tabela.

![](figuras/label.png)

A classificação de risco dos bairros foi  estabelecida em Alto(cor vermelha) para bairros que fossem registrados mais que 50 focos de dengue,Médio(cor azul) para bairros que portassem entre 20 e 50 focos de dengue e para bairros com menos de 20 focos foi atribuido risco Baixo(cor verde).


![](figuras/risco.png)


# Ordenação dos dados

Na aplicação foram estabelecidos dois tipos de ordenação : a opção de ordenar por ordem alfabética(Push Button- Ordenar por nome) ou ordenar pela quantidade de focos encontrados( do menor para maior)-(Push Button - Ordenar por quantidade).

![](figuras/ord1.png)


# Armazenamento dos dados

Ao acessar a opção do "Menu" na borda superior da interface o usuário tem a opção de armazenar os dados cadastrados ou carregar dados de um arquivo já pronto. Sendo válido destacar que ao carregar os dados as estatísticas já seram atualizadas na aplicação.

![](figuras/save1.png)


![](figuras/carg.png)

![](figuras/save2.png)

![](figuras/car1.png)

# Modificar Dados

Por fim,caso o usuário deseje alterar os dados direto na tabela da aplicação, basta clicar duas vezes na célula desejada e a aplicação irá perguntar ao usuário qual a mudança desejada e em seguida realizará as mudanças desejadas.Entretanto, as mudanças só podem ser feitas com os bairros e a quantidade de focos, já que o terceiro parâmetro é gerado a partir dos anteriores.

![](figuras/cel.png)

![](figuras/bar.png)

![](figuras/foc.png)

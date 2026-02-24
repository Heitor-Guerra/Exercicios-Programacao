CREATE DATABASE cadastro;
USE cadastro;


CREATE TABLE pessoas (

    id INT NOT NULL AUTO_INCREMENT,
    -- NOT NULL: Obriga o preenchimento
    -- AUTO_INCREMENT: Começa em 1 e vai aumentando
    nome VARCHAR(30) NOT NULL,
    -- VARCHAR (a): Aceita até 30 char, mas otimiza o espaço
    nascimento DATE NOT NULL,
    sexo ENUM('M', 'F'),
    -- ENUM (a, b, ...): Só aceita as entradas iguais ao aconjunto (a, b, ...)
    peso DECIMAL(5, 2),
    -- DECIMAL(a,b): 'a' é o numero de algs e 'b' é o número de casas decimais
    -- Ex (5,2): Min=-999.99, Max=999.99
    altura DECIMAL(3, 2),
    nacionalidade VARCHAR(15) DEFAULT 'Brasil',
    -- DEFAULT: Se não  digitar nada, vai para o padrao
    PRIMARY KEY (id)
    -- PRIMARY KEY (a): o atributo a é a chave que identifica o dado 

) DEFAULT CHARSET = utf8 ;

SHOW DATABASES ;
SHOW TABLES ;
DESCRIBE pessoas ;



DROP DATABASE cadastro ;

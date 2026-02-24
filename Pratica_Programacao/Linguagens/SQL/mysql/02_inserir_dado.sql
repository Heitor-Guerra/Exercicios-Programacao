CREATE DATABASE cadastro;
-- DDL: Data Definition Language (Definição)

USE cadastro;


CREATE TABLE pessoas (
-- DDL
    id INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(30) NOT NULL,
    nascimento DATE,
    sexo ENUM('M', 'F'),
    altura DECIMAL(3, 2),
    peso DECIMAL(5, 2),
    nacionalidade VARCHAR(15) DEFAULT 'Brasil',
    PRIMARY KEY (id)

) DEFAULT CHARSET = utf8 ;


-- -----------------------------------------------------------------------


INSERT INTO pessoas
(nome, nascimento, sexo, peso, altura)
-- DML: Data Manipulation Language
-- Definição dos tipos de dados a serem entrados
VALUES
('Godofredo', '1984-01-01', 'M', '78.3', '1.9') ;
-- Os dados propriamente ditos


INSERT INTO pessoas
(nome, nascimento, sexo, nacionalidade)
VALUES
('Maria', '1999-10-20', 'F', 'Portugal') ;

INSERT INTO pessoas VALUES
(DEFAULT, 'Claire', '2003-05-20', 'F', '1.7', '60.43', DEFAULT) ;
-- Quando os dados são inseridos na ordem, pode omitir a definição

INSERT INTO pessoas VALUES
(DEFAULT, 'Ana', '1980-04-30', 'F', '1.55', '50.86', 'EUA'),
(DEFAULT, 'Pedro', '1998-07-21', 'M', '1.85', '90.49', DEFAULT),
(DEFAULT, 'Arthur', '1999-10-20', 'M', '2.10', '125.87', DEFAULT),
(DEFAULT, 'Sophie', '2003-09-01', 'F', '1.63', '60.35', 'França') ;
-- Múltipla inserção


-- ---------------------------------------------------------------------


SHOW DATABASES ;
SHOW TABLES ;
SELECT * FROM pessoas ;


DROP DATABASE cadastro ;

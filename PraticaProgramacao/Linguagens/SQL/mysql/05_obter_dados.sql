CREATE DATABASE cadastros;
USE cadastros;

CREATE TABLE pessoas (
  id INT NOT NULL AUTO_INCREMENT,
  nome VARCHAR(30) NOT NULL,
  nascimento DATE,
  sexo ENUM('M','F'),
  altura DECIMAL(3,2),
  peso DECIMAL(5,2),
  nacionalidade VARCHAR(30) DEFAULT 'Brasil',
  PRIMARY KEY(id)
);

INSERT INTO pessoas (nome, nascimento, sexo, altura, peso, nacionalidade) VALUES
('João Silva', '1985-03-15', 'M', 1.78, 75.50, 'Brasil'),
('Maria Silva', '1990-07-22', 'F', 1.65, 62.30, 'Brasil'),
('Carlos Santos', '1978-11-30', 'M', 1.85, 88.00, 'Brasil'),
('Ana Costa', '1995-05-10', 'F', 1.70, 68.90, 'Brasil'),
('Pedro Alves', '1982-09-05', 'M', 1.76, 80.20, 'Brasil'),
('Juliana Pereira', '1992-12-18', 'F', 1.63, 59.70, 'Brasil'),
('Fernando Lima', '1975-06-25', 'M', 1.79, 85.50, 'Brasil'),
('Camila Rocha', '1988-02-14', 'F', 1.68, 65.80, 'Brasil'),
('Ricardo Silva', '1991-08-08', 'M', 1.82, 90.10, 'Brasil'),
('Amanda Silva', '1994-04-03', 'F', 1.72, 70.40, 'Brasil'),
('Lucas Nunes', '1987-10-19', 'M', 1.75, 77.60, 'Brasil'),
('Isabela Ferreira', '1993-01-28', 'F', 1.66, 63.20, 'Brasil'),
('Marcos Duarte', '1979-03-07', 'M', 1.88, 92.30, 'Brasil'),
('Tatiane Moraes', '1986-07-11', 'F', 1.61, 58.90, 'Brasil'),
('Roberto Castro', '1980-12-25', 'M', 1.74, 83.40, 'Brasil'),
('Patrícia Gomes', '1996-09-14', 'F', 1.69, 67.10, 'Brasil'),
('Eduardo Barbosa', '1983-05-30', 'M', 1.81, 87.70, 'Brasil'),
('Larissa Silva', '1997-02-09', 'F', 1.64, 61.50, 'Brasil'),
('Daniel Ribeiro', '1977-08-12', 'M', 1.77, 79.80, 'Brasil'),
('Vanessa Cardoso', '1989-11-21', 'F', 1.73, 71.90, 'Brasil'),
('Alexandre Dias', '1984-06-17', 'M', 1.83, 89.50, 'Brasil'),
('Carolina Teixeira', '1998-04-26', 'F', 1.60, 57.30, 'Brasil'),
('Gustavo Henrique', '1981-10-05', 'M', 1.76, 81.20, 'Brasil'),
('Débora Moreira', '1992-03-19', 'F', 1.67, 66.80, 'Brasil'),
('Bruno Monteiro', '1976-01-15', 'M', 1.80, 86.00, 'Brasil'),
('Suzana Ramos', '1995-08-08', 'F', 1.65, 64.10, 'Brasil'),
('Fábio Correia', '1987-12-30', 'M', 1.78, 82.70, 'Brasil'),
('Nathalia Peixoto', '1993-07-22', 'F', 1.71, 69.50, 'Brasil'),
('Leonardo Pires', '1978-04-18', 'M', 1.84, 91.80, 'Brasil'),
('Marina Luz', '1990-05-29', 'F', 1.62, 60.40, 'Brasil'),
('Rafael Queiroz', '1985-02-11', 'M', 1.79, 84.60, 'Brasil'),
('Bianca Andrade', '1996-11-03', 'F', 1.68, 65.20, 'Brasil'),
('Thiago Nascimento', '1982-08-27', 'M', 1.77, 78.90, 'Brasil'),
('Gabriela Farias', '1994-06-14', 'F', 1.74, 72.30, 'Brasil'),
('Hugo Siqueira', '1979-09-09', 'M', 1.86, 94.20, 'Brasil'),
('Renata Batista', '1988-01-23', 'F', 1.63, 62.70, 'Brasil'),
('Paulo César', '1980-07-07', 'M', 1.75, 80.50, 'Brasil'),
('Leticia Maia', '1997-10-31', 'F', 1.70, 68.40, 'Brasil'),
('Maurício Freitas', '1975-12-12', 'M', 1.82, 88.90, 'Brasil'),
('Yasmin Porto', '1991-04-05', 'F', 1.66, 63.80, 'Brasil'),
('Diego Azevedo', '1986-03-28', 'M', 1.78, 83.10, 'Brasil'),
('Jéssica Sales', '1999-02-17', 'F', 1.69, 66.50, 'Brasil'),
('André Luiz', '1983-11-19', 'M', 1.81, 86.70, 'Brasil'),
('Simone Barros', '1990-08-02', 'F', 1.65, 64.90, 'Brasil'),
('Sérgio Moura', '1977-05-24', 'M', 1.76, 82.00, 'Brasil'),
('Cristina Tavares', '1993-12-08', 'F', 1.72, 70.80, 'Brasil'),
('Rodrigo Medeiros', '1984-09-16', 'M', 1.85, 90.60, 'Portugal'),
('Luana Santos', '1995-01-25', 'F', 1.67, 67.70, 'Brasil'),
('Antônio Carlos', '1976-06-13', 'M', 1.80, 85.30, 'Brasil'),
('Miguel Soares', '1981-07-04', 'M', 1.77, 79.20, 'Espanha');


-- ----------------------------------------------------------------


-- SELECT * FROM pessoas
-- ORDER BY peso, altura, nome DESC;
  -- ORDER BY: ordenar pelo atributo passado (Menor para o Maior)
  -- DESC: Inverte a ordem (Maior para o menor)
  -- ASC: Normal (Ascendente)

-- SELECT nome, nascimento, sexo FROM pessoas;
  -- Nos parametros do select, passa os desejados (nome, nascimento e sexo)

-- SELECT nome, nascimento FROM pessoas
-- WHERE nacionalidade = 'Portugal';
-- ORDER BY nome;
  -- WHERE: Filtra as linhas

-- SELECT nome FROM pessoas
-- WHERE (altura < 1.7 AND peso > 67) XOR (nascimento > '1990-01-01' AND nacionalidade = 'Brasil')
-- ORDER BY nome;
  -- NOT: "não" lógico
  -- AND: "e" lógico
  -- OR: "ou" lógico
  -- XOR: "ou exclusivo"

-- SELECT nome FROM pessoas
-- WHERE altura BETWEEN '1.65' AND '1.7';
  -- BETWEEN: Dentro de uma faixa de valores

-- SELECT nome FROM pessoas
-- WHERE altura IN (1.7, 1.8, 1.75);
  -- IN: Dentro de um conjunto de valores

-- SELECT DISTINCT nacionalidade FROM pessoas;
  -- DISTINCT: Pega todos os dados que são diferentes entre si

-- SELECT nome FROM pessoas
-- WHERE nome LIKE '%Silva%';
  -- LIKE: Procura padrões digitados
  -- Wildcard(%): Significa que pode ser qualquer coisa
  -- Wildcard(_): Exige que tenha exatamente um caracter na posicao

-- SELECT COUNT(*) FROM pessoas
-- WHERE nome LIKE '%silva%';
  -- COUNT(a): Conta quantas do atributo a existem

-- SELECT nome, MAX(altura) FROM pessoas
-- WHERE peso > 80;
  -- MAX(a): Retorna o numero máximo da tabela
  -- MIN(a): Mesma coisa

-- SELECT AVG(altura) FROM pessoas;
  -- SUM(a): Soma os numeros do atributo
  -- AVG(a): Retorna a média do atributo

-- SELECT nacionalidade, COUNT(nome) FROM pessoas
-- WHERE peso > 79
-- GROUP BY nacionalidade
-- HAVING nacionalidade != 'Brasil';
  -- GROUP BY: agrupa  os dados de acordo com o atributo 
  -- HAVING: Semelhante ao WHERE, mas para GROUP 

SELECT altura, COUNT(peso) FROM pessoas
WHERE peso > 70
GROUP BY altura
HAVING altura > (SELECT AVG(altura) FROM pessoas);


-- ----------------------------------------------------------------


DROP DATABASE cadastros;

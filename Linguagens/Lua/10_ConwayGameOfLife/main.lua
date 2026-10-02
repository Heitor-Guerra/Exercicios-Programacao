--- @param lines integer
--- @param columns integer
--- @return table
local function readMatrix(lines, columns)
  local matrix = {}
  for i = 1, lines do
    matrix[i] = {}
    for j = 1, columns do
      matrix[i][j] = io.read("n")
    end
  end
  return matrix
end

local dy = { -1, -1, -1, 0, 0, 1, 1, 1 }
local dx = { -1, 0, 1, -1, 1, -1, 0, 1 }

--- @param matrix table
--- @param i integer      line position
--- @param j integer      column position
--- @return integer
local function countNeighbor(matrix, i, j, l, c)
  local n = 0;
  for k = 1, #dx do
    local ni, nj = i + dy[k], j + dx[k]
    if ni >= 1 and ni <= l and nj >= 1 and nj <= c then
      n = n + (matrix[ni][nj] or 0)
    end
  end
  return n;
end

--- @param matrix table
--- @param i integer      line position
--- @param j integer      column position
--- @param l integer
--- @param c integer
--- @return integer
local function changeCell(matrix, i, j, l, c)
  local n = countNeighbor(matrix, i, j, l, c)
  if matrix[i][j] == 0 and n == 3 then
    return 1
  elseif matrix[i][j] == 1 and (n == 3 or n == 2) then
    return 1
  else
    return 0
  end
end

--- @param matrix table
--- @param l integer
--- @param c integer
--- @param gen integer
--- @return table
local function simulate(matrix, l, c, gen)
  for g = 1, gen do
    local newMatrix = {}
    for i = 1, l do
      newMatrix[i] = {}
      for j = 1, c do
        newMatrix[i][j] = changeCell(matrix, i, j, l, c)
      end
    end
    matrix = newMatrix
  end
  return matrix
end


local function main()
  --- @type integer
  local l, c = io.read("n"), io.read("n")
  ---@type table
  local matrix = readMatrix(l, c)

  --- @type integer
  local generations = io.read("n")

  matrix = simulate(matrix, l, c, generations)
  for i = 1, l do
    local str = ""
    for j = 1, c do
      str = str .. matrix[i][j] .. " "
    end
    print(str)
  end
end
main()

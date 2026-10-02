local function main()
  --- @type number
  local n = io.read("n")

  --- @type table
  local matrix = { [1] = { 1 } }

  print(matrix[1][1])
  for i = 2, n, 1 do
    --- @type table
    local array = {}

    --- @type string
    local line = ""
    for j = 1, i, 1 do
      local num1 = matrix[i - 1][j - 1] or 0
      local num2 = matrix[i - 1][j] or 0
      array[j] = num1 + num2
      line = line .. array[j] .. " "
    end
    print(line)
    matrix[i] = array
  end
end

main()

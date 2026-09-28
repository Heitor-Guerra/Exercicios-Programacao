local function main()
  print("Choose a number.");
  local number = io.read("n");
  print(string.format("The prime Factors of %d are: ", number))


  local primeFactors = {}

  for i = 2, number, 1 do
    if number % i == 0 then
      table.insert(primeFactors, i)
    end

    while number % i == 0 do
      number = number / i;
    end
  end

  for index, value in ipairs(primeFactors) do
    print(string.format("indice %d: %d", index, value))
  end
end

main()

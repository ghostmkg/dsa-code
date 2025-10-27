const countries = [
  { name: 'United States', population: 331002651, continent: 'North America', capital: 'Washington, D.C.' },
  { name: 'China', population: 1439323776, continent: 'Asia', capital: 'Beijing' },
  { name: 'Brazil', population: 212559417, continent: 'South America', capital: 'Brasília' },
  { name: 'United Kingdom', population: 67886011, continent: 'Europe', capital: 'London' },
  { name: 'South Africa', population: 59308690, continent: 'Africa', capital: 'Pretoria, Cape Town, Bloemfontein' },
];

// 1. Print the names of all countries.
console.log('the names of all countries');
countries.forEach(item=>console.log(item.name))

// 2. Find the country with the largest population.
console.log('the country with the largest population:',countries.reduce((a,b)=>a.population>b.population?a:b));
 
// 3. Find the total population of all countries.
let sum=0
countries.forEach(item=>sum+=item.population)
console.log('total population of all countries:',sum);

// 4. Find all countries in a specific continent (e.g., Asia).
console.log('All countries in Asia:');
countries.forEach(item=>item.continent==='Asia'?console.log(item.name):false)

// 5. Print the names of capitals with more than one city.
console.log('Names of countrie with more than one capital:',countries.filter(country=>country.capital.includes(',')));


// 6. Sort countries based on population (descending order).
console.log('countries based on population (descending order):');
console.log([...countries].sort((a,b)=>b.population-a.population));


// 7. Find the country with the smallest population.
console.log('country with the smallest population',countries.reduce((a,b)=>
    a.population<b.population?a:b));

// 8. Find the country with the longest name.
console.log('country with the longest name',countries.reduce((a,b)=>
    a.name.length>b.name.length?a:b));

// 9. Find the country with the shortest name.
console.log('country with the shortest name',countries.reduce((a,b)=>
    a.name.length<b.name.length?a:b));

// 10. Find the average population of all countries.
sum=0
countries.forEach(item=>sum+=item.population)
console.log('average population of all countries:',sum/countries.length);
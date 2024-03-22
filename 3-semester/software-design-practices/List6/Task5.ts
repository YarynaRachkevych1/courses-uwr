type User = {
  name: string;
  age: number;
  occupation?: string;
};
  
type Admin = {
  name: string;
  age: number;
  role?: string;
};

// export type Person = User | Admin;
export type Person = User & Admin;

export const persons: Person[] = [
  {
  name: "Jan Kowalski",
  age: 17,
  occupation: "Student",
  },
  {
  name: "Tomasz Malinowski",
  age: 20,
  role: "Administrator",
  },
];

function logPerson(person: Person) {
  let additionalInformation: string = "";
  
  if (person.role) additionalInformation = person.role;
  else if (person.occupation) additionalInformation = person.occupation;
  console.log(`- ${person.name}, ${person.age}, ${additionalInformation}`);
  }
  
logPerson(persons[0])
logPerson(persons[1])
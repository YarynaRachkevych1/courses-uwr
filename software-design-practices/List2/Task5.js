const book = {
    name: 'Pet Sematary',
    author: 'Stephen King',
    year: 1983,
    printDescription: function(){
        return this.name + ', ' + this.author
    },

    get Name(){
        return this.name
    },

    set Name(name_){
        this.name = name_;
    }
}

console.log(book.printDescription())
console.log(book.Name)
book.Name = 'Misery';
console.log(book.Name)

// Dodanie pola i metody:
Object.defineProperty(book, 'pages', {
    value: '310'})

book.printAuthor = function() {
    return this.author;
};

Object.defineProperty(book, 'foo', {
    value: function() { return 1 }})


// Dodanie nowej właściwości z akcesorem get i set
Object.defineProperty(book, 'newProperty', {
    get: function() {
        return this.author + ' is the author';
    },
    set: function(value) {
        this.author = value;
    }
})

console.log(book)
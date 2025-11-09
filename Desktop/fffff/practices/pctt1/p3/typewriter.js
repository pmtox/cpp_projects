class Typewriter {
constructor(el, words, opts = {}){
this.el = el;
this.words = words;
this.loop = opts.loop ?? true;
this.typeSpeed = opts.typeSpeed ?? 120;
this.deleteSpeed = opts.deleteSpeed ?? 60;
this.delayBetween = opts.delayBetween ?? 1000;
this.text = '';
this.wordIndex = 0;
this.charIndex = 0;
this.isDeleting = false;
this.tick();
}


tick(){
const currentWord = this.words[this.wordIndex % this.words.length];


if(this.isDeleting){
this.charIndex--;
this.text = currentWord.slice(0, this.charIndex);
} else {
this.charIndex++;
this.text = currentWord.slice(0, this.charIndex);
}


this.el.textContent = this.text;


let timeout = this.isDeleting ? this.deleteSpeed : this.typeSpeed;


if(!this.isDeleting && this.charIndex === currentWord.length){
timeout = this.delayBetween;
this.isDeleting = true;
} else if(this.isDeleting && this.charIndex === 0){
this.isDeleting = false;
this.wordIndex++;
timeout = 400;
if(!this.loop && this.wordIndex >= this.words.length){
return; // stop
}
}


setTimeout(() => this.tick(), timeout + Math.random()*50);
}
}


// init
const el = document.getElementById('type');
const words = ['Galaxies', 'Nebulae', 'Supernovas', 'Exoplanets', 'Black holes'];
new Typewriter(el, words, {typeSpeed:110, deleteSpeed:60, delayBetween:1000, loop:true});
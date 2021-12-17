const p1={
    score: 0,
    display: document.querySelector('#p1display'),
    button: document.querySelector('#p1button')
}

const p2={
    score: 0,
    display: document.querySelector('#p2display'),
    button: document.querySelector('#p2button')
}

const resetbutton = document.querySelector('#resetbutton');
const winningscoreselect = document.querySelector('#playto');
let winningscore=3;
let isgameover = false;

function updatescore(p,o){
    if(!isgameover){
        p.score+=1;
        if(p.score===winningscore){
            isgameover = true;
            p.button.disabled = true;
            o.button.disabled = true;
            p.display.classList.add("has-text-success");
            o.display.classList.add("has-text-danger");
            o.button.classList.remove('has-background-info');
            p.button.classList.remove('has-background-info');
        }
        p.display.textContent = p.score;
    }
}


p1.button.addEventListener('click',()=>{
    updatescore(p1,p2);
});
p2.button.addEventListener('click',()=>{
    updatescore(p2,p1)
});
p1.button.addEventListener('mouseover',()=>{
    p1.button.classList.add("has-background-info");
})
p1.button.addEventListener('mouseout',()=>{
    p1.button.classList.remove('has-background-info');
})
p2.button.addEventListener('mouseover',()=>{
    p2.button.classList.add("has-background-info");
})
p2.button.addEventListener('mouseout',()=>{
    p2.button.classList.remove('has-background-info');
})


winningscoreselect.addEventListener('change',()=>{
    winningscore = parseInt(winningscoreselect.value);
    reset();
})

resetbutton.addEventListener('click',reset);

function reset(){
    isgameover=false;
    for(let p of [p1,p2])
    {
        p.score=0;
        p.display.textContent=0;
        p.button.disabled = false;
        p.display.classList.remove('has-text-success','has-text-danger');
        p.button.classList.remove('has-background-info');
    }
}
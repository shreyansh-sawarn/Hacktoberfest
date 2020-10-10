let coin = ['Heads', 'Tails'];

function coinflip() {
    let rnd = Math.round(Math.random());
    let flip = coin[rnd];
    console.log('You flipped the coin...');
    setTimeout( () => { console.log(flip + '!!'); }, 1000);
}
coinflip();

const f = Deno.readTextFileSync("m.txt").replace(/\r/g,"").split("\n");
const ln = f.map(a => a.split(/\s+/g).map(a => parseInt(a)).toSorted());
for(let i=2;i<=36;i++){
    console.log(ln.map(a => a[0].toString(i)).join(" "));
}

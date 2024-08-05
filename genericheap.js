class MaxHeap{
    constructor(cmp){
        this.arr = [];
        this.cmp=cmp;
    }

    upheapify(idx){
        while(idx>0){
            let pi = Math.floor((idx-1)/2);

            if(this.cmp(this.arr[pi] ,  this.arr[idx])){
                let temp = this.arr[pi];
                this.arr[pi]= this.arr[idx];
                this.arr[idx]= temp;
                idx= pi;
            }else{
                break;
            }
        }
    } 
    insert(data){
        this.arr.push(data);
        this.upheapify(this.arr.length-1);
    }

    downheapify(idx){

        while(idx<this.arr.length){
            let leftidx = (2*idx)+1;
            let rightidx = (2*idx)+2;
            let maxel = idx;
            if(leftidx<this.arr.length && this.cmp(this.arr[maxel],this.arr[leftidx] )){
                maxel= leftidx;
            }if(rightidx < this.arr.length && this.cmp(this.arr[maxel],this.arr[rightidx]) ){
                maxel = rightidx;
            }

            if(maxel == idx)break;
            let temp = this.arr[maxel];
            this.arr[maxel]=this.arr[idx];
            this.arr[idx]= temp;
            idx = maxel;
        }

    }
    remove(){
        if(this.arr.length==0)return 0;
        let idxtodelete= 0;
        let lastidx = this.arr.length-1;

        let temp = this.arr[idxtodelete];
        this.arr[idxtodelete]= this.arr[lastidx];
        this.arr[lastidx]= temp;
        this.arr.pop();
        this.downheapify(0);
    }
    display(){
        console.log(this.arr);
    }

}
let mx = new MaxHeap((a,b)=>{
    return a>b; // maxheap
    // a>b   min heap
});
mx.insert(2);
mx.insert(3);
mx.insert(4);
mx.insert(0);
mx.display();
mx.remove();
mx.display();


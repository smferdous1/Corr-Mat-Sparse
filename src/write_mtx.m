%write graph in mtx format

function write_mtx(U,V,E,n,filename)
   
    D_mtx = [[n n size(E,1)];[V U E]];
    %filename = strcat(dirname,'synthetic_',num2str(n),'.mtx');
    dlmwrite(filename,D_mtx(1,:),'delimiter',' ','precision','%d');
    dlmwrite(filename,D_mtx(2:end,:),'delimiter',' ','-append');
end

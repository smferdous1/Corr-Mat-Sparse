clear all;
input_file = '../data/b_30/*.edgelist'
files = dir(input_file);
prefix = '../data/b_30/'
n=360;
map=[];
N = size(files,1);
N_samples = 4;
AllD=zeros(N,N_samples,n,n);
for i=1:size(files,1)
    fname = files(i).name;
    %find the underscore
    k = strfind(fname,'_');
    id = str2num(fname(1:k-1));
    
    map_id = find(map==id);
    if isempty(map_id)
        map = [map,id];
        map_id = length(map);
    end
    
    sample_id = str2num(fname(k+1));
    
    %read the acutal file
    formatSpec='%d %d';
    fileID = fopen(strcat(prefix,fname),'r');
    sizeA = [2 Inf];
    A = fscanf(fileID,formatSpec,sizeA);
    %make it 1 index
    A = A'+1;
    %n is the order of matrix for our case it is 360
    D = zeros(n);
    ind = sub2ind([n n],A(:,1),A(:,2));
    D(ind) = 1;
    %To make it symmetric
    ind = sub2ind([n n],A(:,2),A(:,1));
    D(ind) = 1;
    
    AllD(map_id,sample_id,:,:) = D;
    
end

data_map = cell(1,2);

data_map{1,1} = AllD;
data_map{1,2} = map;
save('../result/b_30.mat','data_map');


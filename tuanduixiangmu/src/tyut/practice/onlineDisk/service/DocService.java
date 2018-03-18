package tyut.practice.onlineDisk.service;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

import tyut.practice.onlineDisk.dao.DocDao;
import tyut.practice.onlineDisk.model.Doc;

public class DocService {
	private DocDao dao = new DocDao();
	private DateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm");

	/**
	 * ���ݴ�����û�(owner),·��(dir)ɾ���ļ���
	 * @param  String owner,String dir
	 * @return boolean
	 */
	public boolean deleteDir(String owner, String dir) {
		try{
			List<Doc> docs = dao.getAllDocsUnderDir(owner, dir);
			
			for(Doc doc : docs){
				if(doc.getIsdir() == 1){
					dao.deleteDocByDir(owner, doc.getDirectory());
					continue;
				}
				String realdir = doc.getRealdirectory();
				dao.deleteDocByDir(owner, doc.getDirectory());
				
				java.io.File f = new java.io.File(realdir);
				if(f.isFile() && f.exists()) {  
			        f.delete();  
			    }
			}
		} catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}
	/**
	 * ���ݴ�����û�(owner),·��(dir)�����ļ��б�
	 * @param  String owner,String dir
	 * @return List<Doc>
	 */
	public List<Doc> getDocs(String dir, String owner) {
		List<Doc> docs = dao.getDocUnderDir(owner, dir);
		return docs;
	}
	/**
	 * ���ݴ�����û�(owner),·��(dir)ɾ���ļ�
	 * @param  String owner String dir
	 * @return boolean
	 */
	public boolean deleteDoc(String owner, String dir) {
		// TODO Auto-generated method stub
		Doc doc = dao.getDocByOwnerAndDirc(owner, dir);
		String realdir = doc.getRealdirectory();
		
		java.io.File f = new java.io.File(realdir);
		if(f.isFile() && f.exists()) {  
	        f.delete();  
	    }
		return dao.deleteDocByDir(owner, dir);
	}
	/**
	 * ���ݴ�����û�(owner),id(id)�����ļ�����
	 * @param  String owner,String dir
	 * @return boolean
	 */
	public Doc getDocById(int id, String owner) {
		// TODO Auto-generated method stub
		return dao.getDocById(owner, id);
	}
	/**
	 * ���ݴ�����û�(owner),·��(dir)���ļ���(name),�ļ�����ʵ·��(realpath),�ļ��Ĵ�С(long size)
	 * @param  String owner
	 * @param  String dir, String name, String realpath, long size
	 * @return boolean
	 */
	public boolean createDoc(String owner, String dir, String name, String realpath, long size) {
		// TODO Auto-generated method stub
		if(dao.getDocByOwnerAndDirc(owner, dir.equals("")?name:dir + "/" + name) != null){
			return false;
		}
		
		int pid = -1;
		if(!dir.equals("")){
			pid = dao.getDocByOwnerAndDirc(owner, dir).getId();
		}
		
		Doc doc = new Doc();
		doc.setDirectory(dir.equals("")?name:dir + "/" + name);
		doc.setCreatetime(df.format(new Date()));
		doc.setName(name);
		doc.setPid(pid);
		doc.setIsdir(0);
		doc.setOwner(owner);
		doc.setSize(size/1000);
		doc.setRealdirectory(realpath);
		dao.addDoc(doc);
		return true;
	}
	/**
	 * ���ݴ���ĸ�Ŀ¼(pdir),�û�(owner),�ļ�����(name)�����ļ���
	 * @param  String owner,String dir
	 * @return boolean
	 */
	public boolean createDir(String pdir, String owner, String name) {
		// TODO Auto-generated method stub
		try{
			if(dao.getDocByOwnerAndDirc(owner, pdir.equals("")?name:pdir + "/" + name) != null){
				return false;
			}
			Doc pf = null;
			if(!pdir.equals("")){
				pf = dao.getDocByOwnerAndDirc(owner, pdir);
			}
			
			Doc doc = new Doc();
			doc.setCreatetime(df.format(new Date()));
			if(pf == null){
				doc.setDirectory(name);
				doc.setRealdirectory(name);
				doc.setPid(-1);
			} else{
				doc.setDirectory(pf.getDirectory() + "/" + name);
				doc.setRealdirectory(pf.getDirectory() + "/" + name);
				doc.setPid(pf.getId());
			}
			doc.setIsdir(1);
			doc.setName(name);
			doc.setOwner(owner);
			doc.setSize(0);
			dao.addDoc(doc);
		} catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}
	
}
